#include<iostream>
#include<fstream>
using namespace std;
class dummy
{
private:
	int a, b;
public:
	dummy(int A, int B) //constructor to set members(private variables)
	{
		a = A;
		b = B;
	}
	void display() //displaying members of class
	{
		cout << "a = " << a << "\tb = " << b << endl;
	}
};
int main()
{
	fstream myfile;
	myfile.open("testfile.txt", ios::out | ios::binary);
	//if file doesn't exist
	if (!myfile)
	{
		cout << "file does not exist" << endl;
		return -1;
	}
	//creating five objects
	dummy A(1, 2);
	dummy B(4, 5);
	dummy C(7, 8);
	dummy D(9, 10);
	dummy E(43, 45);
	//creating object to copy third object from file
	dummy temp(0, 0);
 
	//writing object to file
	myfile.write((char*)&A, sizeof(A));
	myfile.write((char*)&B, sizeof(B));
	myfile.write((char*)&C, sizeof(C));
	myfile.write((char*)&D, sizeof(D));
	myfile.write((char*)&E, sizeof(E));
	myfile.close(); 
	myfile.open("testfile.txt", ios::in | ios::binary);
	if (!myfile) 
	{
		cout << "file not exist" << endl;
		return 0;
	}
	else
	{
		while (myfile.read((char*)&A, sizeof(A)))
		{
			cout << "Data extracted from file: \n";
			//print the object
			A.display();
		}
 
		myfile.close();
	}
 
	myfile.open("testfile.txt", ios::in | ios::binary);
	myfile.clear();
	myfile.seekg(2 * sizeof(A), myfile.beg); //set file pointer to offset of 2 object size from begining
	myfile.read((char*)&temp, sizeof(temp)); //read object from offset
	cout << "\nThird object from begining is: " << endl;
	temp.display(); //display object
	system("pause");
	return 0;
}

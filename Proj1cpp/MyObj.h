#include <iostream>

using namespace std;


class MyObj {

	friend ostream& operator<<(ostream& os, const MyObj& s); //print content of s
	friend istream& operator>>(istream& os, MyObj& s); //read in value of s

public:

	MyObj(); //create myObj object with values of array containing numbers between 0 to 1000
	MyObj(int, int, int); //create myObj object with array values x, y, z
	MyObj(const MyObj& s); //copy value of s into a new object

	MyObj& operator=(const MyObj& s); 
	bool operator<(const MyObj& s); //return true iff object is less than x

	void reset(); //set compareCount to 0
	int getCount(); //return current value of compareCount

	static int compareCount; //keep track of how many times lessThan() is called

private:

	int a[3]; //array of three integers

};

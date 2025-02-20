#include "MyObj.h"

int MyObj::compareCount = 0;

MyObj::MyObj(int x, int y, int z) //create array with given values x,y,z
{
	  a[0] = x;
	  a[1] = y; 
	  a[2] = z;
}

MyObj::MyObj() //create array array with random numbers
{
	  a[0] = rand() % 1000;
	  a[1] = rand() % 1000;
	  a[2] = rand() % 1000;
}

MyObj::MyObj(const MyObj& s) //copy value of s to new object
{
   for (int i = 0; i < 3; i++)
	a[i] = s.a[i];
}


MyObj&  MyObj::operator=(const MyObj& s) //update the value of array of the object to value of s
{
    for (int i = 0; i < 3; i++)  //loop through array of 3 integers
	    a[i] = s.a[i]; //update each value of array by myObj s array
    return *this; //return myObj 
}

bool  MyObj::operator<(const MyObj& s) //receive myObj object
{
    compareCount++; //increase in order to keep track of how many times lessThan() has been called
    bool res = false; //check to see if object is less than x
    if (a[0] < s.a[0]) 
	    res = true;
    else if ((a[0] == s.a[0]) && (a[1] < s.a[1]))
	    res = true;
    else if ((a[0] == s.a[0]) && (a[1] == s.a[1]) && (a[2] < s.a[2]))
	    res = true;

    return res;  //return true iff object is less than x
}

int MyObj::getCount()
{
    return compareCount; 
}

void MyObj::reset()
{
    compareCount = 0;
}

ostream& operator<<(ostream& os, const MyObj& s)
{
   os << "(" << s.a[0] << " " << s.a[1] << " " << s.a[2] << ")";
   return os;
}

istream& operator>>(istream& is, MyObj& s)
{
   is >> s.a[0] >> s.a[1] >> s.a[2];
   return is;
}

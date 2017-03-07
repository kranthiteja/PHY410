#ifndef StudentRecord_h
#define StudentRecord_h

#include <iostream>
#include <string>
using namespace std;

class StudentRecord {
	string firstname;
	string lastname;
	float marks;
	public:
	float RS() const	{
		return marks;
	}
	void setlast(string last) 
	{
		lastname = last;
	}
	void setfirst(string first) 
	{
		firstname = first;
	}
	void setmarks(float mark)
	{
		marks = mark;
	}
	StudentRecord()
	{
		lastname = "";
		firstname = "";
		marks = 0.0;
	}
}; 
#endif
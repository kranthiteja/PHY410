#include <iostream>
#include "StudentRecord.h"
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;
//defining the function to obtain and define variables throughout the inputted files lines

//declaring our vector of student record classes
vector<StudentRecord> Record;

bool input(istream &in, bool flag)//declaring input function
{
	string last;
	string first;
	float marks;
	string line;
	getline(in, line, ',');
	last = line;
	getline(in, line, ',');
	first = line;
	getline(in, line);
	marks=atof(line.c_str());
	if (flag)
	{
		cout << last << "," << first << "," << marks;
	}
	if (line == "")
		return false;
	else
	{
		return true;
	}
}

//Starting the main program
int main(int argc, char ** argv) {
	//building the elements in the StudentRecords vector with objects of class StudentRecord
	int index = atoi(argv[2]);
	ifstream in(argv[1]);
	int x = 1;
	int count = 0;
	while (x == 1) {
		if(count==(index-1))
			x = input(in,true);
		else 
			x = input(in, false);
		count++;
	}
	//calculating the average of the StudentRecords using the pointer of the StudentRecords vector
	return 0;
}
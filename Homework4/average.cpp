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

float calculate_average(vector<StudentRecord> * StudentListptr) {
	vector<StudentRecord> temp = *StudentListptr;
	float Sum = 0.0;
	for (int i = 0; i < temp.size(); i++) {
		Sum += temp.at(i).RS();
	}
	return (Sum / temp.size());
}

bool input(istream &in)//declaring input function
{
	StudentRecord temp;
	
	string line;
	getline(in, line, ',');
	temp.setlast(line);
	getline(in, line, ',');
	temp.setfirst(line);
	getline(in, line);
	temp.setmarks(atof(line.c_str()));
	if (line == "")
	 return false;
	else
	 { 
	Record.push_back(temp);
	return true; }
}

//Starting the main program
int main(int argc, char ** argv) {
	//building the elements in the StudentRecords vector with objects of class StudentRecord
	ifstream in(argv[1]);
	int x = 1;
	while (x == 1) {
		input(in);
		x = input(in);

	}
	//calculating the average of the StudentRecords using the pointer of the StudentRecords vector
	cout << "The average of the Student's Scores is " << calculate_average(&Record) << endl;

	return 0;
}
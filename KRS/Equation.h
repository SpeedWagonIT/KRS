#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdio>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

class Equation
{
public:

	Equation();
	~Equation();
	void write(ifstream& x, ofstream& y, string name_file);//writing the solution to the prepared file
	void write(ofstream& x, string name_file, string s);//creating a file and writing a solution
	int open_File(ifstream& x, string name);//open an existing file
	void open_File(ofstream& x, string name_file);//create and open a file
	void close_File(ifstream& x);
	void close_File(ofstream& x);

	//converting an element string (const char) to int
	int str_to_int(char x);
};
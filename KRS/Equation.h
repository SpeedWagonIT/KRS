#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdio>
using namespace std;

class Equation 
{
public:
	/*void Print();*/

	Equation();
	~Equation();
	void string_read();
	void write(ifstream& x, ofstream& y, string name_file);//������ ������� � ������������� ����
	void write(ofstream& x, string name_file, string s);//�������� ����� � ������ �������
	int open_File(ifstream& x,string name);//������� ������������ ����
	void open_File(ofstream& x,string name_file);//������� � ������� ����
	void close_File(ifstream& x);
	void close_File(ofstream& x);

	//���������� ��������� �� �������� ����������� � �������� (a, b, c)
	void sort_Equation(int a, int b, int c);

	//�������������� �������� string (const char) � int
	int str_to_int(char x);
};
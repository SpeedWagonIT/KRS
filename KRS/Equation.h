#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Equation 
{
public:
	void Print();

	Equation();
	~Equation();
	void string_read();
	void write(ifstream& x);//������ ������� � ������������� ����
	void write(ofstream& x, string name_file, string s);//�������� ����� � ������ �������
	void open_File(ifstream& x);//������� ������������ ����
	void open_File(ofstream& x, string name_file);//������� � ������� ����
	void close_File(ifstream& x);//������� ������������ ����
	void close_File(ofstream& x);//������� ����� ����
	void delete_Separetor(string s);//�������� ������ ������������

	//���������� ��������� �� �������� ����������� � �������� (a, b, c)
	void sort_Equation(int a, int b, int c);

	//�������������� �������� string (const char) � int
	int str_to_int(char x);
	int calc_var();
};
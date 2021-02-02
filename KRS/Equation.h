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
	void write(ifstream& x);//запись решения в заготовленный файл
	void write(ofstream& x, string name_file, string s);//создание файла и запись решения
	void open_File(ifstream& x);//открыть существующий файл
	void open_File(ofstream& x, string name_file);//создать и открыть файл
	void close_File(ifstream& x);//закрыть существующий файл
	void close_File(ofstream& x);//закрыть новый файл
	void delete_Separetor(string s);//удаление лишних разделителей

	//сортировка уравнения от большего коэфициента к меньшему (a, b, c)
	void sort_Equation(int a, int b, int c);

	//преобразования элемента string (const char) в int
	int str_to_int(char x);
	int calc_var();
};
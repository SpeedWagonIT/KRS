#include "Equation.h"

Equation::Equation()
{

}


Equation::~Equation() 
{


}

void Equation::open_File(ifstream& x) {
	x.open("1.txt");
	if (!x.is_open())
	{
		cout << "файл не найден!" << endl;
	}
	

}

void Equation::open_File(ofstream& x, string name_file) {
	x.open(name_file);

	
}

void Equation::close_File(ifstream& x) {
	x.close();
}

void Equation::close_File(ofstream& x) {
	x.close();
}

void Equation::string_read() {

}

void Equation::write(ifstream& x) {

}


void Equation::write(ofstream& x, string name_file, string s) {
	open_File(x, name_file);
	int* abc = new int[100];
	int* buff =new int[100];
	bool _in_str = false;//out of the line
	bool _zero_a = true;//no coeff "a"
	bool _degree = false;//found the degree
	bool _minus = false;
	int cnt = 0;
	int j = 0;
	int k = 0;
	abc[0] = 0;
	for (int i = 0; i < (int)size(s); i++) {

		if ((str_to_int(s[i]) >= 0 && str_to_int(s[i]) <= 9) && !(_degree) ) {
			buff[k] = str_to_int(s[i]);
			k++;
		}
		if (s[i] == '^')
			_degree = true;
		if (s[i] == '-') {
			_minus = true;
		}
		if (_degree && str_to_int(s[i])== 2) {
			if (k == 0)
				abc[j] = 1;
			if (k>=1) {
				abc[j] = 0;
				int z = 1;
				for (k--; k >= 0; k--) {
					abc[j] += buff[k] * z;
					z *= 10;
				}
				_degree = false;
			}
			if (_minus) {
				abc[j] *= -1;
				_minus = false;
				_degree = false;
			}

			j++;
		}


	}

	cout << abc[0] << endl;
	delete[]	abc;
	delete[]	buff;
	close_File(x);
}

void delete_Separetor(string s) {
	

}

void Equation::sort_Equation(int a, int b, int c) {


}

int Equation::str_to_int(char x) {

	int i = (x - '0');
	return i;
}


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
	int* a = new int[100];
	int* b = new int[100];
	int* c = new int[100];
	int* buff = new int[100];
	bool _in_str = false;//out of the line
	bool _zero_a = true;//no coeff "a"
	bool _degree = false;//found the degree
	int cnt = 0;
	int j = 0;
	int k = 0;
	for (int i = 0; i < (int)size(s); i++) {
		//if (i == 2 )
		//	_in_str = true;
		if (s[i] == '^') {
			_degree = true;
			continue;
		}
		if (s[i] == '-')
		{
			buff[k] = -1;
			k++;
			continue;
		}
		if (s[i] == '+') {
			buff[k] = 1;
			k++;
			continue;
		}
		if (!(str_to_int(s[i]) >= 0 && str_to_int(s[i]) <= 9))
			continue;
		else
		{
			buff[k] = str_to_int(s[i]);
			k++;
		}
		//if (_in_str)
		if (str_to_int(s[i]) == 2 && _degree) {
			if (k == 1 && buff[0] == 2)
				a[j] = 1;

			if (k == 1 && buff[0] == 2){

				for (int z = 1; k > 0; k--) {
					a[j] += buff[k] * z;
					z *= 10;
				}
		}
				j++;
			}

	}
	/*for (int i = 0; i < (int)size(s); i++) {
		if (!(str_to_int(a[i]) >= 0 && str_to_int(a[i]) <= 9) && !('^') && !('x') &&! ('+') && (!'-') &&!('='))
			continue;
		if(_in_str == true)
			if ((s[i]) == '2' && s[i - 1] == '^') {
				if (str_to_int(s[i - 3]) > 0 && str_to_int(s[i - 3]) <= 9)
					a[0] = str_to_int(s[i - 3]);
				if (s[i - 3] == '-')
					a[0] = -1;
			_zero_a = false;
			}
		j++;
		cnt++;
		if (cnt == 3)
			_in_str = true;
		if (_zero_a == true)
			a[0] = 1;
	}*/
	cout << a[0]/*<<"x^2"*/;
	delete[]    buff;
	delete[]	a;
	delete[]	b;
	delete[]	c;
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


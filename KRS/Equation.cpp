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
	x.open(name_file,ios::app);

	
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
	int* abc = new int[3];
	int* buff =new int[100];
	bool _in_str = false;//out of the line
	bool _zero_a = true;//no coeff "a"
	int curr = 0;
	bool _minus = false;
	int cnt = 0;
	int j = 0;
	int k = 0;
	abc[0] = 0;
	
	int _space = 0;
	int _tabs = 0;


	s.erase(remove_if(s.begin(), s.end(), isspace), s.end());


	for (int i = 0; i < (int)size(s); i++) {

		if ((str_to_int(s[i]) >= 0 && str_to_int(s[i]) <= 9) && curr != 1 ) {
			buff[k] = str_to_int(s[i]);
			k++;
		}
		if (s[i] == '^')
			curr = 1;
		if (s[i] == '-') {
			_minus = true;
		}
		if (curr == 1 && str_to_int(s[i])== 2) {
			if (k == 0)
				abc[j] = 1;
			if (k>=1) {
				abc[j] = 0;
				int z = 1;
				for (k--; k >= 0; k--) {
					abc[j] += buff[k] * z;
					z *= 10;
				}
			}
			if (_minus) {
				abc[j] *= -1;
				_minus = false;
			}
			curr = 2;
			j++;
			k = 0;
		}
		if (curr == 2 && s[i] == 'x' && (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '='))
		{
			if(k == 0)
				abc[j] = 1;
			if (k >= 1) {
				abc[j] = 0;
				int z = 1;
				for (k--; k >= 0; k--) {
					abc[j] += buff[k] * z;
					z *= 10;
				}
			}
			if (_minus) {
				abc[j] *= -1;
				_minus = false;
			}
			if (s[i + 1] == '=' && s[i + 2] == '0')
			{
				j++;
				abc[j] = 0;

			}

			curr = 3;
			j++;
			k = 0;
		}
		if ((curr == 3 || curr == 2) && s[i] == '=' && str_to_int(s[i+1])== 0 )
		{
			if (curr == 2)
			{
				abc[j] = 0;
				j++;
				curr = 3;
			}
			if (k >= 1) {
				abc[j] = 0;
				int z = 1;
				for (k--; k >= 0; k--) {
					abc[j] += buff[k] * z;
					z *= 10;
				}
			}
			if (_minus) {
				abc[j] *= -1;
				_minus = false;
			}
			j++;
			k = 0;
		}


	}

	float a = (float)abc[0];
	float b = (float)abc[1];
	float c = (float)abc[2];
	float x1, x2;

	delete[]	abc;

	float D;

	if (a == -1)
		x << " - ";
	if (a < 0)
		x << a;
	if (a > 1)
		x << a;
	x << "x^2";
	if (b == -1)
		x << "-";
	if (b == 1)
		x<<"+";
	if (b < 0)
		x << b;
	if (b > 1)
		x << "+"<<b;
	x << "x";
	if (c > 0)
		x << "+" << c;
	if (c < 0)
		x << c;
	x << "=0" << endl;
	D = pow(b, 2) - 4 * a * c;
	
	x << "D=(" << b << ")^2" << "-4*" << a << "*" << c << "="  << D << endl; 
	if (D < 0)
		x << "Корней нет!\n" << endl;
	if (D == 0) {
		x << "Есть один корень" << endl;
		x1 = ((-1) * b) / (2 * a);
		x << "x=" << "((-1)*" << b << ")/(2*" << a << ")=" << x1 << "\n" << endl;
		}
	if (D > 0){
		x << "Корни есть" << endl;
		x1 = ((-1) * b + sqrt(D)) / (2 * a);
		x2 = ((-1) * b - sqrt(D)) / (2 * a);
		x << "x1=" << "((-1)*" << b << "+(D)^1/2)/(2*" << a << ")=" << x1 << endl;
		x << "x2=" << "((-1)*" << b << "-(D)^1/2)/(2*" << a << ")=" << x2 << "\n" << endl;
		}

	delete[]	buff;
	close_File(x);
}


void Equation::sort_Equation(int a, int b, int c) {


}

int Equation::str_to_int(char x) {

	int i = (x - '0');
	return i;
}


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
	bool flag = false;
	int cnt = 0;
	int j = 0;
	for (int i = 0; i < (int)size(s); i++) {
		if(flag == true)
		if ((s[i]) == '2' && s[i - 1] == '^')
			if (str_to_int(s[i - 3]) > 0 && str_to_int(s[i - 3]) <= 9)
			{
			a[0] = str_to_int(s[i - 3]);

			}
			else {
				a[0] = 0;
				break;
			}
		j++;
		cnt++;
		if (cnt == 3)
			flag = true;
	}
	cout << a[0]<<"x^2";
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
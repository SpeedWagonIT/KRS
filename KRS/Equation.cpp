#include "Equation.h"

Equation::Equation()
{
}


Equation::~Equation() 
{
}

int Equation::open_File(ifstream& x, string name_file) {
	x.open(name_file);
	if (!x.is_open())
		return 0;
	else
		return 1;
	

}

void Equation::open_File(ofstream& x, string name_file) {
	x.open(name_file, std::ios::app);

}

void Equation::close_File(ifstream& x) {
	x.close();
}

void Equation::close_File(ofstream& x) {
	x.close();
}

void Equation::write(ofstream& x, string name_file, string s) {
	open_File(x, name_file);
	int* abc = new int[3];
	int* buff = new int[100];
	bool _in_str = false;//out of the line
	bool _zero_a = true;//no coeff "a"
	bool _equally = false;//flag that this equation
	int curr = 0;//flag that this equation
	bool _minus = false;//flag there is a minus
	int cnt = 0;
	int j = 0;
	int k = 0;

	int _space = 0;
	int _tabs = 0;


	s.erase(remove_if(s.begin(), s.end(), isspace), s.end());

	abc[0] = 0;
	abc[1] = 0;
	abc[2] = 0;
		for (int i = 0; i < (int)size(s); i++) {
			if (s[i] == '=' && str_to_int(s[i + 1]) == 0)
				_equally = true;
			if (s[i] == 'x' && s[i + 1] == '^' && str_to_int(s[i + 2]) == 2)
				curr = 1;
			if (_equally == true && curr == 1)
				break;
			try {
				if (i == ((int)size(s) - 1) && (curr < 1 || _equally == false)) {
					throw 1;
				}
			}
			catch (int err) {
				cout << "Ошибка № "<<err<<" - Неправильно введено уравнение" << endl; //Error № 1 - the equation was entered incorrectly
			}

		}
	
	curr = 0;

	for (int i = 0; i < (int)size(s); i++) {

		if ((str_to_int(s[i]) >= 0 && str_to_int(s[i]) <= 9) && curr != 1) {
			buff[k] = str_to_int(s[i]);
			k++;
		}
		if (s[i] == '^')
			curr = 1;
		if (s[i] == '-') {
			_minus = true;
		}
		if (curr == 1 && str_to_int(s[i]) == 2) {
			if (k == 0)
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
			curr = 2;
			j++;
			k = 0;
		}
		if (curr == 2 && s[i] == 'x' && (s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '='))
		{
			if (k == 0)
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
		if ((curr == 3 || curr == 2) && s[i] == '=' && str_to_int(s[i + 1]) == 0)
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
	float D;

	delete[]	abc;


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
		x << "+";
	if (b < 0)
		x << b;
	if (b > 1)
		x << "+" << b;
	if(b < 0 && b > 0)
	x << "x";
	if (c > 0)
		x << "+" << c;
	if (c < 0)
		x << c;
	x << "=0" << endl;
	D = pow(b, 2) - 4 * a * c;

	x << "D=(" << b << ")^2" << "-4*" << a << "*" << c << "=" << D << endl;
	if (D < 0)
		x << "Корней нет!\n" << endl;//no roots
	if (D == 0) {
		x << "Есть один корень" << endl; //there is 1 root
		x1 = ((-1) * b) / (2 * a);
		x << "x=" << "((-1)*" << b << ")/(2*" << a << ")=" << x1 << "\n" << endl;
	}
	if (D > 0) {
		x << "Корни есть" << endl;//Roots exist
		x1 = ((-1) * b + sqrt(D)) / (2 * a);
		x2 = ((-1) * b - sqrt(D)) / (2 * a);
		x << "x1=" << "((-1)*" << b << "+(D)^1/2)/(2*" << a << ")=" << x1 << endl;
		x << "x2=" << "((-1)*" << b << "-(D)^1/2)/(2*" << a << ")=" << x2 << "\n" << endl;
	}
	delete[]	buff;
	close_File(x);
}

void Equation::write(ifstream& x, ofstream& y, string name_file) {
	try {
		if (!(open_File(x, name_file)))
			throw 2;
	}
	catch (int _err) {
		cout << "Ошибка № " << _err << " - файл не найден." << endl;//Error № 2 - file not found
		return;
	}
	
		string tmp;
		int cnt = 0;
		cout << "Файл открыт успешно!" << endl;//The file is opened successfully
		while(!x.eof()){
			cnt++;
			getline(x, tmp);

		}
		string* temp_s = new string[cnt];
		int _cnt_str = 0;
		x.clear();
		x.seekg(0);
		for (_cnt_str; !(x.eof()); _cnt_str++) {
			getline(x, temp_s[_cnt_str]);
		}
		close_File(x);
		y.open(name_file, std::ios::out | std::ios::trunc);
		

		for (int _string = 0; _string < _cnt_str; _string++) {

			int* abc = new int[3];//mass of coeff
			int* buff = new int[100];//data buffer 
			bool _in_str = false;//out of the line
			bool _zero_a = true;//no coeff "a"
			bool _equally = false;
			int curr = 0;
			bool _minus = false;
			bool _correct_str = true;
			int cnt = 0;
			int j = 0;
			int k = 0;

			tmp = temp_s[_string];

			tmp.erase(remove_if(tmp.begin(), tmp.end(), isspace), tmp.end());

			abc[0] = 0;
			abc[1] = 0;
			abc[2] = 0;

			for (int i = 0; i < (int)size(tmp); i++) {
				if (tmp[i] == '=' && str_to_int(tmp[i + 1]) == 0)
					_equally = true;
				if (tmp[i] == 'x' && tmp[i + 1] == '^' && str_to_int(tmp[i + 2]) == 2)
					curr = 1;
				if (_equally == true && curr == 1)
					break;
				if (i == ((int)size(tmp) - 1) && (curr < 1 || _equally == false)) {
					tmp = temp_s[_string];
					for (int m = 0; m < (int)size(tmp); m++)
					y << tmp[m];
					y << endl;
					_correct_str = false;


				}
			}

			curr = 0;
			if (_correct_str) {
				for (int i = 0; i < (int)size(tmp); i++) {

					if ((str_to_int(tmp[i]) >= 0 && str_to_int(tmp[i]) <= 9) && curr != 1) {
						buff[k] = str_to_int(tmp[i]);
						k++;
					}
					if (tmp[i] == '^')
						curr = 1;
					if (tmp[i] == '-') {
						_minus = true;
					}
					if (curr == 1 && str_to_int(tmp[i]) == 2) {
						if (k == 0)
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
						curr = 2;
						j++;
						k = 0;
					}
					if (curr == 2 && tmp[i] == 'x' && (tmp[i + 1] == '+' || tmp[i + 1] == '-' || tmp[i + 1] == '='))
					{
						if (k == 0)
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
						if (tmp[i + 1] == '=' && tmp[i + 2] == '0')
						{
							j++;
							abc[j] = 0;

						}

						curr = 3;
						j++;
						k = 0;
					}
					if ((curr == 3 || curr == 2) && tmp[i] == '=' && str_to_int(tmp[i + 1]) == 0)
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
				float D;

				delete[]	abc;
				tmp = temp_s[_string];

				if (a == 0 && b == 0 && c == 0)
					continue;

				for (int m = 0; m < (int)size(tmp); m++)
					y << tmp[m];
				y << endl;
				D = pow(b, 2) - 4 * a * c;

				y << "D=(" << b << ")^2" << "-4*" << a << "*" << c << "=" << D << endl;
				if (D < 0)
					y << "Корней нет!"<< endl;//no roots
				if (D == 0) {
					y << "Есть один корень" << endl;//there is 1 root
					x1 = ((-1) * b) / (2 * a);
					y << "x=" << "((-1)*" << b << ")/(2*" << a << ")=" << x1 << "\n" << endl;
				}
				if (D > 0) {
					y << "Корни есть" << endl;//Roots exist
					x1 = ((-1) * b + sqrt(D)) / (2 * a);
					x2 = ((-1) * b - sqrt(D)) / (2 * a);
					y << "x1=" << "((-1)*" << b << "+(D)^1/2)/(2*" << a << ")=" << x1 << endl;
					y << "x2=" << "((-1)*" << b << "-(D)^1/2)/(2*" << a << ")=" << x2 << endl;
				}
				delete[]	buff;

			}
		}
		cout << "Запись произведена успешно!" << endl;//the record is successful
	close_File(y);
	

}

int Equation::str_to_int(char x) {

	int i = (x - '0');
	return i;
}


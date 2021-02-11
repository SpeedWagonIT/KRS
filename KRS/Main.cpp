#include "Equation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;


int main() {
	setlocale(LC_ALL, "Rus");
	Equation equ;
	ifstream fin;
	ofstream fnew,fin_write;
	string name,str;
	char menu;
	

	do {
		system("cls");
		cout << "�������� ��������:" << endl;//select an action
		cout << "[1] ������ �� �����" << endl;//Reading from a file
		cout << "[2] ������ ���� ���������" << endl;//Manual input of equations
		cout << "[3]�����.\n>> ";//Exit
		cin >> menu;
		try {
			switch (menu) {
			case '1':
				cout << "������� �������� ����� ��� ��� ������ ���� (��� .txt)" << endl;//
				cin >> name;
				name += ".txt";
				equ.write(fin, fin_write, name);
				system("Pause");
				break;
			case '2':
				cout << "������� �������� ������ ����� (��� .txt)" << endl;//Enter the name of the new file (without .txt)
				cin >> name;
				name += ".txt";
				cout << "������� ��������� ����  'ax^2+bx+c=0' � ������� 'Enter'" << endl;//Enter equations like 'ax^2+bx+c=0 'and press' Enter
				cout << "��� ��������� ����� �������  STOP" << endl;//To stop typing, type STOP
				for (int i = 0;; i++) {
					getline(cin, str);
					if (str == "STOP")
						break;
					if (i == 0)
						continue;
					equ.write(fnew, name, str);
				}
				system("Pause");
				break;

			case '3':
				break;
			default:
				throw 3;
				break;

			}
		}
		catch (int _err) {
			cout << "������ � " << _err << " - ������������ ���� ��� ������ ��������." << endl;//Error 3 - incorrect input when selecting an action.
			system("Pause");
		}
		
	} while (menu !='3');
	system("Pause");
	return 0;
}
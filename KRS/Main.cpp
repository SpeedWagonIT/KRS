#include "Equation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	Equation ee;
	ifstream fin;
	ofstream fnew,fin_write;
	string name,str;
	char menu;
	

	do {
		system("cls");
		cout << "�������� ��������:" << endl;
		cout << "[1] ������ �� �����" << endl;
		cout << "[2] ������ ���� ���������" << endl;
		cout << "[3]�����.\n>> ";
		cin >> menu;
		switch (menu) {
		case '1':
			cout << "������� �������� ����� ��� ��� ������ ���� (��� .txt)" << endl;
			cin >> name;
			name += ".txt";
			ee.write(fin,fin_write,name);
			system("Pause");
			break;
		case '2':
			cout << "������� �������� ������ ����� (��� .txt)" << endl;
			cin >> name;
			name += ".txt";
			cout << "������� ��������� ����  'ax^2+bx+c=0' � ������� 'Enter'" << endl;
			cout << "��� ��������� ����� �������  STOP" << endl;
			for(int i = 0;;i++) {
				getline(cin, str);
				if (str == "STOP")
					break;
				if(i == 0)
				continue;
				ee.write(fnew, name, str);
			}
			system("Pause");
			break;

		case '3':
			break;

	}
		
	} while (menu !='3');

	cin >> name;
	name += ".txt";

	fin_write.open(name, ios::out | ios::trunc);
	fin_write << "YES";
	fin.close();



	return 0;
}
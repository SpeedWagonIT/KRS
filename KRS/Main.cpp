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
	ofstream fnew;
	string name,str,tmp;
	char menu,menu1;


		do {
			cin >> str;
			ee.write(fnew, name, str);
		} while (str != "STOP");
		cout << "\n�Ѹ!" << endl;
	//do {
	//	system("cls");
	//	cout << "�������� ��������:" << endl;
	//	cout << "[1] ������ �� �����" << endl;
	//	cout << "[2] ������ ���� ���������" << endl;
	//	cout << "[3]�����.\n>> ";
	//	cin >> menu;
	//	switch (menu) {
	//	case '1':

	//		break;
	//	case '2':
	//		cout << "������� �������� ������ �����:" << endl;
	//		cin >> name;
	//		name += ".txt";
	//		cout << "������� ��������� ���� : ax^2+bx+c=0 � ������� 'Enter'" << endl;
	//		cout << ">>";
	//		cin >> str;
	//		tmp = ' ';
	//		tmp += str;
	//		str = tmp;
	//		ee.write(fnew,name,str);
	//		system("Pause");
	//		break;

	//	case '3':
	//		break;

	//}
	//	
	//} while (menu !='3');

	return 0;
}
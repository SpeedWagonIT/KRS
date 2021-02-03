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
		cout << "\nУСё!" << endl;
	//do {
	//	system("cls");
	//	cout << "Выберите действие:" << endl;
	//	cout << "[1] Чтение из файла" << endl;
	//	cout << "[2] Ручной ввод уравнений" << endl;
	//	cout << "[3]Выход.\n>> ";
	//	cin >> menu;
	//	switch (menu) {
	//	case '1':

	//		break;
	//	case '2':
	//		cout << "Введите название нового файла:" << endl;
	//		cin >> name;
	//		name += ".txt";
	//		cout << "Введите уравнения вида : ax^2+bx+c=0 и нажмите 'Enter'" << endl;
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
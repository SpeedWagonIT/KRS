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
		cout << "Выберите действие:" << endl;
		cout << "[1] Чтение из файла" << endl;
		cout << "[2] Ручной ввод уравнений" << endl;
		cout << "[3]Выход.\n>> ";
		cin >> menu;
		switch (menu) {
		case '1':
			cout << "Введите название файла или его полный путь (без .txt)" << endl;
			cin >> name;
			name += ".txt";
			ee.write(fin,fin_write,name);
			system("Pause");
			break;
		case '2':
			cout << "Введите название нового файла (без .txt)" << endl;
			cin >> name;
			name += ".txt";
			cout << "Введите уравнения вида  'ax^2+bx+c=0' и нажмите 'Enter'" << endl;
			cout << "Для остановки ввода введите  STOP" << endl;
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
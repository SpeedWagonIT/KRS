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
		cout << "Âûáåðèòå äåéñòâèå:" << endl;//select an action
		cout << "[1] ×òåíèå èç ôàéëà" << endl;//Reading from a file
		cout << "[2] Ðó÷íîé ââîä óðàâíåíèé" << endl;//Manual input of equations
		cout << "[3]Âûõîä.\n>> ";//Exit
		cin >> menu;
		try {
			switch (menu) {
			case '1':
				cout << "Ââåäèòå íàçâàíèå ôàéëà èëè åãî ïîëíûé ïóòü (áåç .txt)" << endl;///Enter the name of the file (without .txt)
				cin >> name;
				name += ".txt";
				equ.write(fin, fin_write, name);
				system("Pause");
				break;
			case '2':
				cout << "Ââåäèòå íàçâàíèå íîâîãî ôàéëà (áåç .txt)" << endl;//Enter the name of the new file (without .txt)
				cin >> name;
				name += ".txt";
				cout << "Ââåäèòå óðàâíåíèÿ âèäà  'ax^2+bx+c=0' è íàæìèòå 'Enter'" << endl;//Enter equations like 'ax^2+bx+c=0 'and press' Enter
				cout << "Äëÿ îñòàíîâêè ââîäà ââåäèòå  STOP" << endl;//To stop typing, type STOP
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
			cout << "Îøèáêà ¹ " << _err << " - íåêêîðåêòíûé ââîä ïðè âûáîðå äåéñòâèÿ." << endl;//Error 3 - incorrect input when selecting an action.
			system("Pause");
		}
		
	} while (menu !='3');
	system("Pause");
	return 0;
}

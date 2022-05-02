#include<Windows.h>
#include<iostream>
#include<dos.h>
#include<ctime>
class MemoryGame {
	int arr_int[4][4]{1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
	bool arr_boll[4][4] = { true };
	int columnU = 0, rowU = 0, column1 = 0, row1 = 0, points = 0, choose = 0;
public:
	void IQshift() {
		srand(time(NULL));
		const int y = 4; const int x = 4;
		int buf = 0;
		for (int i = 0; i < rand() % 8 + 1; i++) {
			for (int j = 0; j < y; j++) {
				for (int z = 0; z < x - 1; z++) {    // сдвиг вле
					buf = arr_int[j][z + 1];
					arr_int[j][z + 1] = arr_int[j][z];
					arr_int[j][z] = buf;
				}
			}
		}
		for (int i = 0; i < rand() % 8 + 1; i++) {
			for (int j = 0; j < y; j++) {
				for (int z = 0; z < x - 1; z++) {  // сдвиг вправо
					buf = arr_int[j][z];
					arr_int[j][z] = arr_int[j][z + 1];
					arr_int[j][z + 1] = buf;
				}
			}
		}
		for (int i = 0; i < rand() % 8 + 1; i++) {
			for (int j = 0; j < y; j++) {
				for (int z = x - 1; z > 0; z--) {  // вроде рабочий сдвиг влево попытка 2
					buf = arr_int[j][z];
					arr_int[j][z] = arr_int[j][z - 1];
					arr_int[j][z - 1] = buf;
				}
			}
		}
		for (int i = 0; i < rand() % 8 + 1; i++) {
			for (int j = 0; j < y - 1; j++) {
				for (int z = 0; z < x; z++) { //cдвиг вверх
					buf = arr_int[j][z];
					arr_int[j][z] = arr_int[j + 1][z];
					arr_int[j + 1][z] = buf;
				}
			}
		}
		for (int i = 0; i < rand() % 8 + 1; i++) {
			for (int j = y - 1; j > 0; j--) { //сдвиг вниз
				for (int z = 0; z < x; z++) {
					buf = arr_int[j][z];
					arr_int[j][z] = arr_int[j - 1][z];
					arr_int[j - 1][z] = buf;
				}
			}
		}
	}
	void score() {
		if (arr_int[columnU][rowU] == arr_int[column1][row1]) {
			points += 2;
			std::cout << "Есть пара! Продолжайте в том же духе!" << std::endl;
			std::cout << "У вас " << points << " очков" << std::endl;
		}
		else {
			std::cout << "Карты не совпадают! Трай эган епт" << std::endl;
			std::cout << "У вас " << points << " очков" << std::endl;
			arr_boll[columnU][rowU] = false;
			arr_boll[column1][row1] = false;
			Sleep(2000);
			system("cls");
			IQshift();
			std::cout << "  A B C D";
			std::cout << std::endl;
			std::cout << " --------" << std::endl;
			for (int i = 0; i < 4; i++) {
				std::cout << i + 1 << "|";
				for (int j = 0; j < 4; j++) {
					std::cout << "*" << " ";
				}
				std::cout << std::endl;
			}
		}
		if (points == 16) {
			std::cout << "u win!!! " << std::endl << " Постaвте 12 за экзамен =)";
		}
	}
	void bord() {
		std::cout << "  A B C D";
		std::cout << std::endl;
		std::cout << " --------" << std::endl;
		for (int rowU = 0; rowU < 4; rowU++) {
			std::cout << rowU + 1 << "|";
			for (int columnU = 0; columnU < 4; columnU++) {
				if (arr_boll[rowU][columnU]) {
					std::cout << arr_int[rowU][columnU] << " ";
				}
				else {
					std::cout << "*" << " ";
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		score();
	}
	int intput() {
		do {
			std::cout << std::endl;
			std::cout << "Введите номер колноки первой карты: ";
			std::cin >> columnU;
			std::cout << std::endl;
			std::cout << "Введите номер строки первой карты: ";
			std::cin >> rowU;
			std::cout << std::endl;
			std::cout << "Введите номер колонки второй карты: ";
			std::cin >> column1;
			std::cout << std::endl;
			std::cout << "Введите номер строки второй карты: ";
			std::cin >> row1;
			std::cout << std::endl;
			columnU--;
			rowU--;
			column1--;
			row1--;
			arr_boll[columnU][rowU] = true;
			arr_boll[column1][row1] = true;
			bord();
		} while (points != 16);
		return columnU, rowU, column1, row1;
	}
	void match() {
		std::cout << '\t' << '\t' << '\t' << '\t' << "Добро пожаловать в игру 'Память'" << std::endl <<
			"Правила игры:" << std::endl <<
			"Перед вами карты разложенные 'рубашкой' вверх." << std::endl;
		Sleep(1000);
		std::cout << "Ваша задача: поочередно переворачивать по 2 карты." << std::endl;
		Sleep(1000);
		std::cout << "Если перевернутые Вами карты совпадают то вы получаете о4ко" << std::endl;
		Sleep(1000);
		std::cout << "Если нет, то карты переворачиваются и вы продолжаете" << std::endl;
		Sleep(1000);
		std::cout << "Игра считается законченой после открытия всех пар карт";
		IQshift();
		std::cout << "  A B C D";
		std::cout << std::endl;
		std::cout << " --------" << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << i + 1 << "|";
			for (int j = 0; j < 4; j++) {
				arr_boll[i][j] = false;
				std::cout << "*" << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		intput();
	}
};

int main() {
	setlocale(LC_ALL, "RUS");
	MemoryGame start;
	start.match();
}
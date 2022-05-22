#include<Windows.h>
#include<iostream>
#include<dos.h>
#include<ctime>
class MemoryGame {
	int arr_int[4][4]{1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
	bool arr_boll[4][4] = { true };
	int columnU = 0, rowU = 0, column1 = 0, row1 = 0, points = 0, choose = 0, open = 0;
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
		open++;
		if (arr_int[columnU][rowU] == arr_int[column1][row1]) {
			std::cout << "\a";
			points += 2;
			std::cout << "Есть пара! Продолжайте в том же духе!" << std::endl;
			std::cout << "У вас " << points << " очков" << std::endl;
		}
		else {
			Beep(400, 800);
			std::cout << "Карты не совпадают! Трай эган епт" << std::endl;
			std::cout << "У вас " << points << " очков" << std::endl;
			arr_boll[columnU][rowU] = false;
			arr_boll[column1][row1] = false;
			Sleep(2000);
			system("cls");
			bord();
		}
		if (points == 16) {
			std::cout << "u win!!! " << std::endl << " Постaвте 12 за экзамен =)"<<std::endl;
			std::cout << "\t" << "\t" << "\t" << "Статистика:"<<std::endl;
			std::cout << "Вы совершили " << open << " переворотов"<<std::endl;
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
			score();
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
		std::cout << std::endl;
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

class MemoryGameT {
	char arr_int[6][6]{ '1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','@','@', '$', '$', '#', '#','!','!','%','%','&' , '&' , '+', '+', 'X', 'X'};
	bool arr_boll[6][6] = { true };
	int columnU = 0, rowU = 0, column1 = 0, row1 = 0, points = 0, choose = 0, open = 0;
public:
	void IQshift() {
		srand(time(NULL));
		const int y = 6; const int x = 6;
		int buf = 0;
		for (int i = 0; i < rand() % 36 + 1; i++) {
			for (int j = 0; j < y; j++) {
				for (int z = 0; z < x - 1; z++) {    // сдвиг вле
					buf = arr_int[j][z + 1];
					arr_int[j][z + 1] = arr_int[j][z];
					arr_int[j][z] = buf;
				}
			}
		}
		for (int i = 0; i < rand() % 36 + 1; i++) {
			for (int j = 0; j < y; j++) {
				for (int z = 0; z < x - 1; z++) {  // сдвиг вправо
					buf = arr_int[j][z];
					arr_int[j][z] = arr_int[j][z + 1];
					arr_int[j][z + 1] = buf;
				}
			}
		}
		for (int i = 0; i < rand() % 36 + 1; i++) {
			for (int j = 0; j < y - 1; j++) {
				for (int z = 0; z < x; z++) { //cдвиг вверх
					buf = arr_int[j][z];
					arr_int[j][z] = arr_int[j + 1][z];
					arr_int[j + 1][z] = buf;
				}
			}
		}
		for (int i = 0; i < rand() % 36 + 1; i++) {
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
		open++;
		if (arr_int[columnU][rowU] == arr_int[column1][row1]) {
			std::cout << "\a";
			points += 2;
			std::cout << "Есть пара! Продолжайте в том же духе!" << std::endl;
			std::cout << "У вас " << points << " очков" << std::endl;
		}
		else {
			Beep(400, 800);
			std::cout << "Карты не совпадают! Трай эган епт" << std::endl;
			std::cout << "У вас " << points << " очков" << std::endl;
			arr_boll[columnU][rowU] = false;
			arr_boll[column1][row1] = false;
			Sleep(2000);
			system("cls");
			bord();
		}
		if (points == 18) {
			std::cout << "u win!!! " << std::endl << " Постaвте 12 за экзамен =)" << std::endl;
			std::cout << "\t" << "\t" << "\t" << "Статистика:" << std::endl;
			std::cout << "Вы совершили " << open << " переворотов" << std::endl;
		}
	}
	void bord() {
		std::cout << "  A B C D E F";
		std::cout << std::endl;
		std::cout << " ------------" << std::endl;
		for (int rowU = 0; rowU < 6; rowU++) {
			std::cout << rowU + 1 << "|";
			for (int columnU = 0; columnU < 6; columnU++) {
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
	}
	int intput() {
		std::cout << "  A B C D E F";
		std::cout << std::endl;
		std::cout << " ------------" << std::endl;
		for (int rowU = 0; rowU < 6; rowU++) {
			std::cout << rowU + 1 << "|";
			for (int columnU = 0; columnU < 6; columnU++) {
				std::cout << arr_int[rowU][columnU]<< " ";
			}
			std::cout << std::endl;
		}

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
			score();
		} while (points != 18);
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
		std::cout << std::endl;
		IQshift();
		std::cout << "  A B C D E F";
		std::cout << std::endl;
		std::cout << " ------------" << std::endl;
		for (int i = 0; i < 6; i++) {
			std::cout << i + 1 << "|";
			for (int j = 0; j < 6; j++) {
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
	int begin = 0, end = 0, result = 0, choose = 0;
	std::cout << "Нажмите '1' для того чтобы начать игру на уровне сложности 'легкий'" << std::endl <<
		" нажмите '2' для того чтобы начать игру на уровне сложности 'сложный'" << std::endl <<
		" Нажмите '0' что бы выйти из программы";
	std::cin >> choose;
	switch (choose) {
	case 1: {
		begin = clock();
		MemoryGame start;
	start.match();
	end = clock();
	result = end - begin;
	result = (result / 1000);
	std::cout << "Время вашей игры составило: " << result << " секунд"; 

	}
		  break;
	case 2: {
		begin = clock();
		MemoryGameT start;
		start.match();
		end = clock();
		result = end - begin;
		result = (result / 1000);
		std::cout << "Время вашей игры составило: " << result << " секунд"; 

	}
		  break;
	case '0': {
		std::cout << "see u, goodbye =)";
		system("pause");
	}
		  break;
	}	
}
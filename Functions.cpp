#include "Player.h"

bool coin() {
	cout << "\n\n\t\tБросаем монетку!\n";
	bool isMyRound = rand() % 2;
	switch (isMyRound) {
	case 1: cout << "\n\n" << "\tВыпал орёл. Вы стреляете первым.";
		break;
	case 0: cout << "\n\n" << "\tВыпала решка. Первым стреляет противник.";
		break;
	}
	cout << endl;
	system("pause");
	return isMyRound;
}
void Space(int space) // Функция для пробелов
{
	for (int i{ 0 }; i < space; ++i) {
		cout << " ";
	}
}

void showGame(const Player* const player_1, const Player* const player_2) {
	system("cls");
	cout << endl;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (((14 << 4) | 2)));
	cout << "\t\t";
	Space(4);
	for (int i = 0; i < ROW; i++) {
		Space(1);
		cout << player_1->sym[i];
	}
	Space(4);
	cout << "\t\t";
	Space(4);
	for (int i = 0; i < ROW; i++) {
		Space(1);
		cout << player_2->sym[i];
	}
	Space(4);
	cout << endl;
	cout << "\t\t";
	Space(4);
	for (int i = 0; i < ROW; i++) {
		Space(2);
	}
	Space(4);
	cout << "\t\t";
	Space(4);
	for (int i = 0; i < ROW; i++) {
		Space(2);
	}
	Space(4);
	cout << endl;
	for (int i = 0; i < ROW; i++) {
		cout << "\t\t";
		SetConsoleTextAttribute(h, (((14 << 4) | 2)));
		if (i < 9) Space(1);
		cout << player_1->num[i];
		Space(2);
		for (int j = 0; j < COL; j++) {
			SetConsoleTextAttribute(h, (((1 << 4) | 12)));
			Space(1);
			cout << player_1->pole[i][j];
		}
		SetConsoleTextAttribute(h, (((14 << 4) | 2)));
		Space(4);
		cout << "\t\t";
		SetConsoleTextAttribute(h, (((14 << 4) | 2)));
		if (i < 9) Space(1);
		cout << player_2->num[i];
		Space(2);
		for (int j = 0; j < COL; j++) {
			SetConsoleTextAttribute(h, (((1 << 4) | 12)));
			Space(1);
			//cout << player_2->notShowPole[x][y]; // скрытое поле
			cout << player_2->pole[i][j]; // открытое поле
		}
		SetConsoleTextAttribute(h, (((14 << 4) | 2)));
		Space(4);
		cout << endl;
	}

	for (int i{ 0 }; i < 2; ++i) {
		cout << "\t\t";
		for (int j{ 0 }; j < COL + 4; ++j) {
			Space(2);
		}
		cout << "\t\t";
		for (int j{ 0 }; j < COL + 4; ++j) {
			Space(2);
		}
		cout << endl;

	}
	cout << "\n\t";
	SetConsoleTextAttribute(h, (((0 << 4) | 15)));
}

bool shotPlayer(Player * player_1, Player * player_2) {
	string turn;
	while (true) {
		showGame(player_1, player_2);
		bool flag = false;
		int x, y;
		cout << "Ваш ход, " << player_1->name << ": ";
		getline(cin, turn);
		for (int i = 0; i < ROW; i++) {
			if (flag) continue;
			for (int j = 0; j < COL; j++) {
				if (flag) continue;
				if (player_1->moves[i][j] == turn || player_1->moves_small[i][j] == turn) {
					flag = true;
					x = i;
					y = j;
				}
			}
		}
		if (flag)
		{
			if (player_2->pole[x][y] == SHOT_SYMBOL || player_2->pole[x][y] == HIT_SYMBOL) {
				cout << "\tСюда стрелять нельзя! Попробуйте снова\n";
				system("pause");
				system("cls");
			}
			else {
				cout << "\t";
				return shot(x, y, *player_2);
			}
		}
		else {
			cout << "\tКлетки с такими координатами нет! Попробуйте снова\n";
			system("pause");
			system("cls");
		}
	}
}
bool shotBot(Player * player_1, Player * player_2) {
	cout << "Ходит " << player_1->name << ": ";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ". ";
	int x, y;
	do {
		x = rand() % 10;
		y = rand() % 10;
	} while (player_2->pole[x][y] == SHOT_SYMBOL
		|| player_2->pole[x][y] == HIT_SYMBOL);
	cout << player_1->moves[x][y] << "  ";
	return shot(x, y, *player_2);

}
bool shot(int x, int y, Player & enemy) {

	if (enemy.pole[x][y] == SHIP_SYMBOL) {
		enemy.pole[x][y] = HIT_SYMBOL;
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			if (&enemy.pole[x][y] == &*enemy.deck_4.m_ship[i]) {
				for (int i = 0; i < 4; i++) {
					if (*(enemy.deck_4.m_ship[i]) == SHIP_SYMBOL) {
						flag = true;
					}
				}
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				if (&enemy.pole[x][y] == &*enemy.deck_3[i].m_ship[j]) {
					for (int j = 0; j < 3; j++) {
						if (*(enemy.deck_3[i].m_ship[j]) == SHIP_SYMBOL) {
							flag = true;
						}
					}
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				if (&enemy.pole[x][y] == &*enemy.deck_2[i].m_ship[j]) {
					for (int j = 0; j < 2; j++) {
						if (*(enemy.deck_2[i].m_ship[j]) == SHIP_SYMBOL) {
							flag = true;
						}
					}
				}
			}
		}
		if (flag) {
			cout << "Ранил! " << endl;
			system("pause");
			return true;
		}
		else {
			cout << "Убил!" << endl;
			system("pause");
			return true;
		}
	}
	else {
		enemy.pole[x][y] = SHOT_SYMBOL;
		enemy.notShowPole[x][y] = SHOT_SYMBOL;
		cout << "Промах!" << endl;
		system("pause");
		return false;
	}
}

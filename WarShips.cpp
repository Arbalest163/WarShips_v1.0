#include <iostream>
#include <string>
#include <time.h>
#include "Windows.h"
#include "Player.h"
bool shotPlayer(Player* player_1, Player* player_2);
bool shotBot(Player* player_1, Player* player_2);
bool shot(int x, int y, Player& enemy);
void showGame(const Player* const player_1, const Player* const player_2);
bool coin();

int Player::couterBot{ 0 };

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name;
	cout << "Введите Ваше имя: ";
	getline(cin, name);
	Player* player_1 = new Player(name);
	Player* player_2 = new Player;
	bool isMyRound = coin();
	player_1->shipPlacement();
	player_2->shipPlacement();
	while (true) {
		if (player_1->getLoss()) break;
		if (player_2->getLoss()) break;
		while (isMyRound) {
			showGame(player_1, player_2);
			if (player_2->getLoss()) break;
			if (!shotPlayer(player_1, player_2))
				isMyRound = false;
			player_2->setLoss();
		}
		while (!isMyRound) {
			showGame(player_1, player_2);
			if (player_1->getLoss()) break;
			if (!shotBot(player_2, player_1))
				isMyRound = true;
			player_1->setLoss();
		}
	}
	player_1->getLoss() ? cout << "\nПобедил " << player_2->name : cout << "\nПобедил " << player_1->name;
	cout << endl;
	system("pause");
	//delete player_1;
	//delete player_2;
}


#include "Player.h"

Player::Player(const string string) : name{ string } // ����������� ������,��������� ������ ����
{
	int rusA = 192; // ������� ����� ���������� �����.
	for (int i = 0; i < ROW; i++) {
		if (rusA == 201 || rusA == 233) ++rusA;
		sym[i] = rusA;
		sym_small[i] = rusA + 32;
		num[i] = to_string(i + 1);
		rusA++;
	}
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			moves[i][j] = sym[j] + num[i];
			moves_small[i][j] = sym_small[j] + num[i];
			pole[i][j] = WATER_SYMBOL;
			notShowPole[i][j] = WATER_SYMBOL;
		}
	}

	couterBot++; //������������� ��� �������� ������ ����
}
Player& Player::shipClear() // ������� ����
{
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			pole[i][j] = WATER_SYMBOL;
			notShowPole[i][j] = WATER_SYMBOL;
		}
	}
	return *this;
}

Player& Player::shipPlacement() { //����� ���������� ���� ���������
	int count = 0; // ������� ����������� �������� ��� �����������. ���������� ������ ����� ���������� ��������.
	int directionShip = 0; // ����������� �������. 1.�������������; 2.�����������;
	bool flag = true;  // ���� ���� �� ��������� � �����, ������, �� ���� ����������� �������� ���������� �������.
	int x, y;
	// �������������� �������.
	while (true) {
		x = rand() % ROW;
		y = rand() % COL;
		flag = true;
		directionShip = 1 + rand() % 2;
		//cout << x << "  " << y << "  D4 " << directionShip << " ; ";  // �������� ��������� �����������
		if (directionShip == 1 && y < COL - 3) { // �������� ������ � ������ ������
			for (int i{ (x == 0 ? 0 : -1) }; i < (x == ROW - 1 ? 1 : 2); i++) {
				for (int j{ (y == 0 ? 0 : -1) }; j < (y == COL - 4 ? 4 : 5); j++) {
					if (pole[x + i][y + j] != WATER_SYMBOL) {
						flag = false;
						break;
					}
				}
			}
		}
		else if (directionShip == 2 && x < ROW - 3) {  // �������� ������ � ������ ������
			for (int i{ (y == 0 ? 0 : -1) }; i < (y == COL - 1 ? 1 : 2); i++) {
				for (int j{ (x == 0 ? 0 : -1) }; j < (x == ROW - 4 ? 4 : 5); j++) {
					if (pole[x + j][y + i] != WATER_SYMBOL) {
						flag = false;
						break;
					}
				}
			}
		}
		else continue;
		if (flag) {
			for (int i{ 0 }; i < 4; i++) {
				directionShip == 1 ? pole[x][y + i] = SHIP_SYMBOL : pole[x + i][y] = SHIP_SYMBOL;
				directionShip == 1 ? deck_4.m_ship[i] = &(pole[x][y + i]) : deck_4.m_ship[i] = &(pole[x + i][y]);
			}
			break;
		}
	}

	// 3 �������� �������
	while (true) {
		while (true) {
			x = rand() % ROW;
			y = rand() % COL;
			flag = true;
			directionShip = 1 + rand() % 2;
			//cout << x << "  " << y << "  D3 " << directionShip << " ; ";  // �������� ��������� �����������
			if (directionShip == 1 && y < COL - 2) {
				for (int i = (x == 0 ? 0 : -1); i < (x == ROW - 1 ? 1 : 2); i++) {
					for (int j = (y == 0 ? 0 : -1); j < (y == COL - 3 ? 3 : 4); j++) {
						if (pole[x + i][y + j] != WATER_SYMBOL) {
							flag = false;
							break;
						}
					}
				}
			}
			else if (directionShip == 2 && x < ROW - 2) {
				for (int i = (y == 0 ? 0 : -1); i < (y == COL - 1 ? 1 : 2); i++) {
					for (int j = (x == 0 ? 0 : -1); j < (x == ROW - 3 ? 3 : 4); j++) {
						if (pole[x + j][y + i] != WATER_SYMBOL) {
							flag = false;
							break;
						}
					}
				}
			}
			else continue;
			if (flag) {
				for (int i = 0; i < 3; i++) {
					directionShip == 1 ? pole[x][y + i] = SHIP_SYMBOL : pole[x + i][y] = SHIP_SYMBOL;
					directionShip == 1 ? deck_3[count].m_ship[i] = &(pole[x][y + i])
						: deck_3[count].m_ship[i] = &(pole[x + i][y]);
				}
				break;
			}
		}
		count++;
		if (count == 2) {
			count = 0;
			break;
		}
	}
	// ����������� �������
	while (true) {
		while (true) {
			x = rand() % ROW;
			y = rand() % COL;
			flag = true;
			directionShip = 1 + rand() % 2;
			//cout << x << "  " << y << "  D2 " << directionShip << " ; ";  // �������� ��������� �����������
			if (directionShip == 1 && y < COL - 1) {
				for (int i = (x == 0 ? 0 : -1); i < (x == ROW - 1 ? 1 : 2); i++) {
					for (int j = (y == 0 ? 0 : -1); j < (y == COL - 2 ? 2 : 3); j++) {
						if (pole[x + i][y + j] != WATER_SYMBOL) {
							flag = false;
							break;
						}
					}
				}
			}
			else if (directionShip == 2 && x < ROW - 1) {
				for (int i = (y == 0 ? 0 : -1); i < (y == COL - 1 ? 1 : 2); i++) {
					for (int j = (x == 0 ? 0 : -1); j < (x == ROW - 2 ? 2 : 3); j++) {
						if (pole[x + j][y + i] != WATER_SYMBOL) {
							flag = false;
							break;
						}
					}
				}
			}
			else continue;
			if (flag) {
				for (int i = 0; i < 2; i++) {
					directionShip == 1 ? pole[x][y + i] = SHIP_SYMBOL : pole[x + i][y] = SHIP_SYMBOL;
					directionShip == 1 ? deck_2[count].m_ship[i] = &(pole[x][y + i])
						: deck_2[count].m_ship[i] = &(pole[x + i][y]);
				}
				break;
			}
		}
		count++;
		if (count == 3) {
			count = 0;
			break;
		}
	}
	// ������������ �������
	while (true) {
		while (true) {
			x = rand() % ROW;
			y = rand() % COL;
			flag = true;
			//cout << x << "  " << y << "  D1 " << " ; ";  // �������� ��������� �����������
			for (int i = (x == 0 ? 0 : -1); i < (x == ROW - 1 ? 1 : 2); i++) {
				for (int j = (y == 0 ? 0 : -1); j < (y == COL - 1 ? 1 : 2); j++) {
					if (pole[x + i][y + j] != WATER_SYMBOL) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				pole[x][y] = SHIP_SYMBOL;
				deck_1[count].m_ship[0] = &(pole[x][y]);
				break;
			}
		}
		count++;
		if (count == 4) {
			count = 0;
			break;
		}
	}

	return *this;

}

void Player::setLoss() {
	for (int i = 0; i < 4; i++)
		if (*deck_4.m_ship[i] == SHIP_SYMBOL)
			return;
	for (int i{ 0 }; i < 2; i++)
		for (int j{ 0 }; j < 3; j++)
			if (*deck_3[i].m_ship[j] == SHIP_SYMBOL)
				return;
	for (int i{ 0 }; i < 3; i++)
		for (int j{ 0 }; j < 2; j++)
			if (*deck_2[i].m_ship[j] == SHIP_SYMBOL)
				return;
	for (int i{ 0 }; i < 4; i++)
		if (*deck_1[i].m_ship[0] == SHIP_SYMBOL)
			return;
	LOSS = true;
	return;
}

bool Player::getLoss() { return LOSS; }

Player::~Player() {

}

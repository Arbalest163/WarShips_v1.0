#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include "Windows.h"
#define ROW 10 // ������ ����
#define COL 10 // ������� ����
#define WATER_SYMBOL " " //  ������ ����
#define SHIP_SYMBOL "@" // ������ �������
#define SHOT_SYMBOL "*" // ������ �������� �� ����
#define HIT_SYMBOL "X" // ������ ����������� �������
using namespace std;


class Ship {
public:
	string** m_ship;
	Ship(int numberDecks = 1) {
		if (numberDecks) {
			m_ship = new string * [numberDecks];
		}
		else m_ship = nullptr;
	}
	~Ship() {
		delete[] * m_ship;
	}
};

class Player {
public:
	string name;
	string sym[ROW]; //��������� �����
	string sym_small[ROW]; // ��������� �����
	string num[COL]; // �����
	string moves[ROW][COL]; //���� � ���������� �������
	string moves_small[ROW][COL]; // ���� � ���������� �������
	string pole[ROW][COL]; //�������� ����
	string notShowPole[ROW][COL]; // ������� ����
	static int couterBot; // ������� �������� �����;
	bool LOSS = false;
	Ship deck_4{ 4 }; // �������������� �������
	Ship deck_3[2]{ 3,3 }; //����������� �������
	Ship deck_2[3]{ 2,2,2 }; //������������ �������
	Ship deck_1[4]; // ������������ �������

	Player(const string string = "Bot " + to_string(couterBot)); // �����������
	Player& shipPlacement(); // ����� ����������� ��������
	Player& shipClear(); // ����� ������ ����
	friend bool shot(int x, int y, Player& enemy); //�������� ��������� �� ���������� �������
	void setLoss(); // ��������� ���������
	bool getLoss(); // ��������� ���������� � ���������
	~Player();

};

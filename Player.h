#pragma once
#include <iostream>
#include <string>
#include <time.h>
#include "Windows.h"
#define ROW 10 // Строки поля
#define COL 10 // Столбцы поля
#define WATER_SYMBOL " " //  Символ воды
#define SHIP_SYMBOL "@" // Символ корабля
#define SHOT_SYMBOL "*" // Символ выстрела по воде
#define HIT_SYMBOL "X" // Символ попаданияпо кораблю
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
	string sym[ROW]; //Заглавные буквы
	string sym_small[ROW]; // Прописные буквы
	string num[COL]; // Цифры
	string moves[ROW][COL]; //Ходы с заглавными буквами
	string moves_small[ROW][COL]; // ходы с прописными буквами
	string pole[ROW][COL]; //Открытое поле
	string notShowPole[ROW][COL]; // Скрытое поле
	static int couterBot; // Счетчик создания ботов;
	bool LOSS = false;
	Ship deck_4{ 4 }; // четырёхпалубный корабль
	Ship deck_3[2]{ 3,3 }; //трёхпалубный корабль
	Ship deck_2[3]{ 2,2,2 }; //двухпалубный корабль
	Ship deck_1[4]; // однопалубный корабль

	Player(const string string = "Bot " + to_string(couterBot)); // Конструктор
	Player& shipPlacement(); // Метод расстановки кораблей
	Player& shipClear(); // Метод очстки поля
	friend bool shot(int x, int y, Player& enemy); //Проверка попадания по вражескому кораблю
	void setLoss(); // Установка поражения
	bool getLoss(); // Получение информации о поражении
	~Player();

};

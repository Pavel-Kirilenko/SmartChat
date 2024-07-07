#pragma once
#include<string>

using namespace std;

class PersData // класс с персональными данными пользователя чата
{
	string persName;     // имя пользователя 
	string persPassword;  // пароль пользователя
	int messageNum;       // количество сообщений пользователя
public:
	PersData(); // конструктор класса, который используется при регистрации пользователя
};
class PersDataArray // класс-контейнер для хранения пользователей чата с их
	// с их персональными данными
{
	int persNumber;   // количество пользователей и длина массива
	PersData* person; // указатель на начало массива с данными пользователей
public:
	PersDataArray(int _persNumber);
	~PersDataArray();                 // деструктор для освобождения динамически выделенной памяти
	PersData& operator[](int index);  // функция доступа к элементу массива по индексу
};
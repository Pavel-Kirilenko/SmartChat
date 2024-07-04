#pragma once
#include<string>

using namespace std;

class PersData // класс с персональными данными пользователя чата
{
	string persName;     // имя пользователя 
	string persPassword;  // пароль пользователя
public:
	PersData(); // конструктор класса, который используется при регистрации пользователя
};
#include<iostream>
#include"HeaderSC.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	PersData user; // инициализация данных пользователя
	PersDataArray arrayData(2);  // создание массива для храниения пользователей из десяти элементов
	arrayData[1] = user;
	return 0;
}
#include <iostream>
#include "HeaderSC.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");                // строка для корректного отображения кириллических символов
	ItemDataArray<PersData> arrayData(0); // создание массива с данными пользователей
	PersData person(0);                   // регистрация пользователя
	PersData person2(0);                  // регистрация пользователя
	arrayData.setItem(0, person);
	arrayData.setItem(1, person2);
	PersData tempPers;
	tempPers = arrayData.getItem(0);
	for (int i = 0; i < 2; i++)
	{
		tempPers = arrayData.getItem(i);
		cout << tempPers.getCharValue(1) << " " << tempPers.getCharValue(2) << endl;
	}


	
	return 0;
}





	//ItemDataArray<int> arrayData(4);  // создание массива для храниения пользователей из десяти элементов
	//arrayData.Remove(3);
	//PersData person;
	//person.setValue(1, "Павел");
	//person.setValue(2, "Пароль");
	//person.setValue(10);
	//arrayData.InsertBefore(person, 2);
	//PersData tempPers;
	//for (int i = 0; i < 4; i++)
	//{
	//	tempPers = arrayData[i];
	//	cout << tempPers.getStringValue(1) << " " << tempPers.getStringValue(2) << endl;
	//}


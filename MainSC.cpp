#include <iostream>
#include "HeaderSC.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	system("chcp 1251");                  // строка для корректного отображения кириллических символов
	ItemDataArray<PersData> persArray(0); // создание массива с данными пользователей
	ItemDataArray<PersMessage> messArray(0); // создание массива с сообщениями
	PersData curPerson;  //  текущий пользователь/
	string curName;      //  текущее имя пользователя
	string curPassWord;  //  текущий пароль пользователя
	PersData arrPerson;  //  один из пользователей в массиве (переменная для обработки данных в циклах)
	bool persPresence = false;  //  переменная, показывающая существование пользователя с данным именем и паролем

	short contProcNumber = 0;  // переменная, которая отвечает за продолжение программы
	while (true)
	{
		while (contProcNumber < 1 || contProcNumber > 3)  //  защита от некорректного ввода выбора дальнейших действий
		{
			cout << "Выберите действие: 1 - войти; 2 - зарегистрироваться; 3 - выход из программы." << endl;
			cin >> contProcNumber;
		}
		if (contProcNumber == 1)
		{
			if (persArray.getSize())  // если массив пользователей не равен нулю
			{
				cout << "Введите имя: ";
				getline(cin, curName);
				getline(cin, curName);
				cout << "Введите пароль: ";
				getline(cin, curPassWord);
				for (int i = 0; i < persArray.getSize(); i++)
				{
					arrPerson = persArray.getItem(i);
					if (curName == arrPerson.getCharValue(1) && curPassWord == arrPerson.getCharValue(2))  // проверка существования имени
						                                                                                   // и пароля пользователя
					{
						curPerson = arrPerson;
						persPresence = true;
						cout << "Пользователь найден?";
					}
				}
				if (persPresence = false) cout << "Пользователя с такими именем и паролем не существует. Проверьте правильность ввода данных";
			}
			else
			{
				cout << "В чате еще нет зарегистрированных пользователей." << endl;
			}
		}

		if (contProcNumber == 2)
		{
			curPerson.InitPersData(0);          // регистрация пользователя
			persArray.setItem(persArray.getSize(), curPerson);  // занесение данных пользователя в массив пользователей
			curName = curPerson.getCharValue(1);  // текущее имя пользователя
			cout << "Добро пожаловать в чат, " << curName << "!" << endl;
		}
		if (contProcNumber == 3) break;  //  выход из программы

		contProcNumber = 0;

	}
	
	/**
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

	PersMessage message("Павел");
	**/
	
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


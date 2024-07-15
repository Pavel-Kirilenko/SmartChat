#include <iostream>
#include "HeaderSC.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	system("chcp 1251");                     // строка для корректного отображения кириллических символов
	ItemDataArray<PersData> persArray(0);    // создание массива с данными пользователей
	ItemDataArray<PersMessage> messArray(0); // создание массива с сообщениями
	PersData curPerson;  //  текущий пользователь
	string curName;      //  текущее имя пользователя
	string curPassWord;  //  текущий пароль пользователя
	PersData arrPerson;  //  текущий пользователь в массиве (во внутренних циклах)
	PersMessage curMessage;  //  текущее сообщение
	PersMessage arrMessage;  //  одно из сообщений в массиве (во внутренних циклах)
	string arrName;      //  текущее имя владельца сообщения (во внутренних циклах)
	string arrAdress;    //  текущее имя адресата сообщения (во внутренних циклах)
	string arrMessContent;   //  содержание текущего сообщения (во внутренних циклах)
	unsigned messNumber = 0; //  номер текущего сообщения (сообщения нумеруются от нуля и далее в порядке создания)
	bool persPresence = false;  //  переменная, показывающая существование пользователя с данным именем и паролем

	string contProcNumber = "0";  // переменная, которая отвечает за продолжение программы, тип продиктован необходимостью устойчивости
	                              // программы при вводе некорректных данных
	while (true)
	{
		while (persPresence == false)  // цикл продолжается пока пользователь не вошел в аккаунт или не зарегистирировался
		{
			while (contProcNumber != "1" && contProcNumber != "2" && contProcNumber != "3")  //  защита от некорректного ввода выбора дальнейших действий
			{
				cout << "Выберите действие: 1 - войти; 2 - зарегистрироваться; 3 - выход из программы." << endl;
				getline(cin, contProcNumber);
			}
			persPresence = false;
			if (contProcNumber == "1")
			{
				if (persArray.getSize())  // если массив пользователей не равен нулю
				{
					cout << "Введите имя: ";
					getline(cin, curName);
					cout << "Введите пароль: ";
					getline(cin, curPassWord);
					for (unsigned i = 0; i < persArray.getSize(); i++)
					{
						arrPerson = persArray.getItem(i);
						if (curName == arrPerson.getCharValue(1) && curPassWord == arrPerson.getCharValue(2))  // проверка существования имени
							// и пароля пользователя
						{
							curPerson = arrPerson;
							persPresence = true;
						}
					}
					if (persPresence == false)
					{
						cout << "Пользователь с такими именем и паролем не найден. Проверьте правильность ввода данных" << endl;
						contProcNumber = "0";
					}
				}
				else
				{
					cout << "В чате еще нет зарегистрированных пользователей." << endl;
					contProcNumber = "0";
				}
			}

			if (contProcNumber == "2")
			{
				curPerson.InitPersData(0);          // регистрация пользователя
				persArray.setItem(persArray.getSize(), curPerson);  // занесение данных пользователя в массив пользователей
				curName = curPerson.getCharValue(1);  // текущее имя пользователя
				cout << "Добро пожаловать в чат, " << curName << "!" << endl;
				persPresence = true;
			}

			if (contProcNumber == "3") break;  //  выход из цикла
		}
		if (contProcNumber == "3") break;  //  выход из программы

		if (messArray.getSize())  //  если в массиве есть сообщения
		{
			for (unsigned i = 0; i < messArray.getSize(); i++)  //  вывод на экран сообщений для конкретного пользователя
			{
				arrMessage = messArray.getItem(i);           //  определение текущего сообщения
				arrName = arrMessage.getCharValue(1);        //  определение имени владельца сообщения
				arrAdress = arrMessage.getCharValue(2);      //  определение имени адресата сообщения
				arrMessContent = arrMessage.getCharValue(3); //  определение содержания сообщения
				if (arrName == curName || arrAdress == curName || arrAdress == "всем")  //  если сообщение имеет отношение к текущему пользователю
				{
					cout << "Сообщение # " << arrName << " пишет " << arrAdress << ":" << endl;  // то оно выводится на консоль
					cout << arrMessContent << endl;
				
				}
			}
		}
		else
		{
			cout << "У вас нет сообщений" << endl;
		}
		contProcNumber = "0";
		while (true) // цикл продолжается пока пользователь не захочет выйти из профиля или из программы
		{
			while (contProcNumber != "1" && contProcNumber != "2" && contProcNumber != "3")  //  защита от некорректного ввода выбора дальнейших действий
			{
				cout << "Выберите действие: 1 - отправить сообщение; 2 - удалить сообщение ; 3 - выйти из профиля." << endl;
				getline(cin, contProcNumber);
			}
			if (contProcNumber == "3") 
			{
				persPresence = false;  //  пользователь выходит из профиля
				break;                 //  выход из цикла
			}
			if (contProcNumber == "1")
			{
				for (int i = 0; i < messArray.getSize(); i++)
				{
					arrMessage = messArray.getItem(i);                  //  текущее сообщение из массива
					cout << arrPerson.getCharValue(1) << "; ";          //  вывод имен других пользователей
				}
				curMessage.InitPersMessage(curName, messNumber);        //  формирование сообщения
				messArray.setItem(messArray.getSize(), curMessage);     // занесение сообщения в массив сообщений
				messNumber++;  //  увеличение счетчика сообщений на единицу
				contProcNumber = "0";
			}
		}

		contProcNumber = "0";

	}
	
	
	return 0;
}




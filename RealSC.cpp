#include "HeaderSC.h"
#include <iostream>

using namespace std;

PersData::PersData()  // конструктор класса, используется при регистрации пользователя
{
	string persName = "A";      // инициализация временной переменной в которую будет записано имя пользователя
	string persPassword = "B";  // инициализация временной переменной в которую будет записан пароль пользователя
	cout << "Введите ваше имя:" << endl;  // ввов имени пользователя
	cin >> persName;
	cout << "Введите пароль:" << endl;
	cin >> persPassword;                  // ввод пароля пользователя
	this->persName = persName;
	this->persPassword = persPassword;
}


PersDataArray::PersDataArray(int _persNumber) : // конструктор контейнера
	persNumber{ _persNumber }   // для хранения пользователей чата
{
	// здесь надо будет поймать исключение, если количество пользователей меньше нуля
	if (_persNumber > 0) person = new PersData[_persNumber]{};
}
PersDataArray::~PersDataArray()  // деструктор
{
	delete[] person;
}
void PersDataArray::Erase()                     // функция удаления массива
{
	person = nullptr;
	persNumber = 0;
}
PersData& PersDataArray::operator[](int index)  // функция доступа к элементу массива по индексу
{
	// здесь необходимо будет поймать исключение, если индекс выходит за пределы массива
	return person[index];
}
int PersDataArray::getLength() const            // функция-геттер определения длины массива
{
	return persNumber;
}
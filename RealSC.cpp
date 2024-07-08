#include "HeaderSC.h"
#include <iostream>
#include <cassert>    // for assert()

using namespace std;
PersData::PersData()  // конструктор по умолчанию
{
	this->persName = "persName";
	this->persPassword = "persPassword";
	this->messageNum = 1;
}
PersData::PersData(string persName, string persPassword, int messageNum)  // конструктор класса, используется при регистрации пользователя
{
	this->persName = persName;
	this->persPassword = persPassword;
	this->messageNum = messageNum;
}
string PersData::getStringValue(int fieldNumber) const // функция-геттер для вывода полей класса типа string
{
	return (fieldNumber == 1 ? this->persName : this->persPassword);
}
void PersData::setValue(int numValue, string value) // функция сеттер для инициализации полей типа string
{
	(numValue == 1 ? this->persName = value : this->persPassword = value);
}
void PersData::setValue(int value) // функция сеттер для инициализации полей типа int
{
	this->messageNum = value;
}

PersDataArray::PersDataArray(int _persNumber) : // конструктор контейнера
	persNumber{ _persNumber }                   // для хранения пользователей чата
{
	assert(_persNumber >= 0);   // возможно модифицировать отбработку исключений с помощью throw/catch
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
	assert(index >= 0 && index < persNumber);   // возможно модифицировать отбработку исключений с помощью throw/catch
	return person[index];
}
int PersDataArray::getLenght() const            // функция-геттер определения длины массива
{
	return persNumber;
}
void PersDataArray::InsertBefore(PersData value, int index) // вставка элемента перед другим элементом с известным индексом
{
	assert(index >= 0 && index <= persNumber); // возможно модифицировать отбработку исключений с помощью throw/catch
	PersData* data{ new PersData[persNumber + 1] };      // создание нового массива на единицу длиннее предыдущего
	copy_n(person, index, data);               // копирование всех элементов до индекса
	data[index] = value;                       // добавление нового элемента в массив
	copy_n(person + index, persNumber - index, data + index + 1); // копирование всех элементов после индекса
	delete[] person;       // удаление старого массива и использование нового взамен
	person = data;
	++persNumber;
}
void PersDataArray::Remove(int index)            // функция удаления элемента с известным индексом
{
	assert(index >= 0 && index < persNumber); // возможно модифицировать отбработку исключений с помощью throw/catch
	if (persNumber == 1)            // если в массиве всего один элемент, то массив удаляется
	{
		Erase();
		return;
	}
	PersData* data{ new PersData[persNumber - 1] }; // создание нового массива с длиной на один элемент короче
	copy_n(person, index, data);     // копирование всех элементов до индекса
	copy_n(person + index + 1, persNumber - index - 1, data + index); // копирование всех элементов после индекса
	delete[] person;  // удаление старого массива и создание нового
	person = data;
	--persNumber;
}

#pragma once
#include <cassert> // for assert()
#include<iostream>
#include<string>


using namespace std;

class PersData // класс с персональными данными пользователя чата
{
protected:
	string persName;      // имя пользователя
	string persDirWord;  // пароль пользователя (адресат сообщения в классе-наследнике)
	int messageNum;       // количество сообщений пользователя
public:
	PersData() // конструктор по умолчанию
	{
		this->persName = "persName";
		this->persDirWord = "persDirWord";
		this->messageNum = 1;
	}

	PersData(int messageNum) // конструктор класса, используется при регистрации пользователя
	{
        setlocale(LC_ALL, "");                // строка для корректного отображения кириллических символов
        string persName; string persDirWord; // переменные, в которых храняться имя и пароль пользователей
        cout << "Введите ваше имя: ";
        getline(cin, persName);
        cout << "Введите пароль: ";
        getline(cin, persDirWord);
        this->persName = persName;
        this->persDirWord = persDirWord;
		this->messageNum = messageNum;
	}

	string getCharValue(int fieldNumber) const // функция-геттер для вывода полей класса типа string
	{
		return (fieldNumber == 1 ? this->persName : this->persDirWord);
	}

	void setValue(int numValue, string value) // функция сеттер для инициализации полей типа string
	{
		(numValue == 1 ? this->persName = value : this->persDirWord = value);
	}

	void setValue(int value) // функция сеттер для инициализации полей типа int
	{
		this->messageNum = value;
	}
};

class PersMessage final : public PersData  // класс сообщений пользователей - наследник класса PersData
{
    string messText;  // Содержание сообщения
public:
    PersMessage(string persName)
    {
        string _persDirWord;       // кому сообщение
        string _messText;          // содержание сообщения
        this->persName = persName; // от кого сообщение
        cout << "Кому отправить сообщение (введите имя пользователя): ";
        getline(cin, _persDirWord);
        this->persDirWord = _persDirWord;
        cout << "Введите текст сообщения: ";
        getline(cin, _messText);
        this->messText = _messText;
    }
};

template <typename T>  class ItemDataArray  // шаблонный класс для хранения данных пользователей и сообщений
{
private:
	unsigned _size;		// Размер массива
	T* _data;			// Указатель на массив

public:
    ItemDataArray(unsigned size) // Конструктор
    {
        _size = size;
        _data = new T[_size];
    }
    ~ItemDataArray() // Деструктор
    {
        delete[] _data;
    }
    void setItem(int index, T val) // Запись элемента в массив
    {
        if (index >= 0 && index < _size)
            _data[index] = val;

        T* data = new T[_size + 1];      // создание нового массива на один элемент больше существующего
        std::copy_n(_data, _size, data); // копирование в новый массив всех элементов
        data[index] = val;               // запись нового элемента в массив
        //std::copy_n(_data + index + 1, _size - index - 1, data + index); // копирование всех элементов за удаляемым элементом
        delete[] _data; // удаление старых данных
        _data = data;
        ++_size; // увеличение поля размера массива на единицу
    }
    T getItem(int index) const // Получение элемента массива
    {
        if (index >= 0 && index < _size)
            return _data[index];
    }
    unsigned getSize() // Получение размера массива
    {
        return _size;
    }
   ItemDataArray(ItemDataArray& a) // Конструктор копирования
    {
        _size = a._size; // Копируем значение поля размера массива
        _data = new T[_size]; // Выделяем память для нового массива
        for (auto i = 0; i < _size; i++)
            _data[i] = a._data[i]; // Копируем элементы массива
    }
    ItemDataArray<T>& operator=(ItemDataArray& a) // Оператор присваивания
    {
        if (this != &a) { // Проверяем, чтобы не присвоить массив сам в себя, this указатель на текущий объект в памяти
            _size = a._size; // Копируем значение поля размера массива
            delete[] _data; // Освобождаем память от старого массива
            _data = new T[_size]; // Выделяем память в куче для нового массива
            for (auto i = 0; i < _size; i++)
                _data[i] = a._data[i]; // Копируем элементы массива
        }
        return *this; // Возвращаем указатель на новый объект
    }
    void Erase() // удаление массива
    {
        delete[] _data;
        _data = nullptr;
        _size = 0;
    }
    void Remove(unsigned index) // удаление элемента
    {
        assert(index >= 0 && index < _size); // проверка находится ли удаляемый элемент в пределах массива (реализовтаь с помощью throw/catch
        if (_size == 1) // если массив состоит только из одного элемента, то он удаляется
        {
            Erase();
            return;
        }
        T* data = new T[_size - 1]; // создание нового массива на один элемент меньше существующего
        std::copy_n(_data, index, data); // копирование в новый массив всех элементов до номера удаляемого элемента
        std::copy_n(_data + index + 1, _size - index - 1, data + index); // копирование всех элементов за удаляемым элементом
        delete[] _data; // удаление старых данных
        _data = data;
        --_size; // уменьшение поля размера массива на единицу
    }
};


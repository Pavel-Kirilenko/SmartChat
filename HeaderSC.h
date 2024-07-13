#pragma once
#include <cassert> // for assert()

class PersData // класс с персональными данными пользователя чата
{
	const char* persName;     // имя пользователя
	const char* persPassword;  // пароль пользователя
	int messageNum;       // количество сообщений пользователя
public:
	PersData() // конструктор по умолчанию
	{
		this->persName = "persName";
		this->persPassword = "persPassword";
		this->messageNum = 1;
	}

	PersData(const char* persName, const char* persPassword, int messageNum) // конструктор класса, используется при регистрации пользователя
	{
		this->persName = persName;
		this->persPassword = persPassword;
		this->messageNum = messageNum;
	}

	const char* getCharValue(int fieldNumber) const // функция-геттер для вывода полей класса типа const char*
	{
		return (fieldNumber == 1 ? this->persName : this->persPassword);
	}

	void setValue(int numValue, const char* value) // функция сеттер для инициализации полей типа const char*
	{
		(numValue == 1 ? this->persName = value : this->persPassword = value);
	}

	void setValue(int value) // функция сеттер для инициализации полей типа int
	{
		this->messageNum = value;
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


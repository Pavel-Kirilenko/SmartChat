#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

class PersData {          // класс с персональными данными пользователя чата
protected:             
    string persName;     
    string persDirWord;
    string textInfo;
    int messageNum;
public:
    PersData();
    void initPersData(int messageNum);            // функция для регистрации пользователя
    string getCharValue(int fieldNumber) const;   // функция-геттер для вывода полей класса типа string
    int getCharValue() const;                     // функция-геттер для вывода поля класса типа int
    void setValue(int numValue, string value);    // функция сеттер для инициализации полей типа string
    void setValue(int value);                     // функция сеттер для инициализации полей типа int
};

class PersMessage final : public PersData {       // класс сообщений пользователей - наследник класса PersData
public:
    void initPersMessage(string persName, int messageNum);
};

template <typename T>
class ItemDataArray {     // шаблонный класс для хранения данных пользователей и сообщений
private:
    int _size;
    unique_ptr<T[]> _data;
public:
    ItemDataArray(int size) : _size(size), _data(make_unique<T[]>(size)) {}
    ~ItemDataArray() = default;

    void setItem(int index, T val) {           // Запись элемента в массив
        if (index >= 0 && index < _size) {
            _data[index] = val;
        }

        unique_ptr<T[]> data = make_unique<T[]>(_size + 1);
        std::copy_n(_data.get(), _size, data.get());
        data[index] = val;
        _data = move(data);
        ++_size;
    }

    T getItem(int index) const {             // Получение элемента массива
        if (index >= 0 && index < _size) {
            return _data[index];
        }
        throw out_of_range("Index out of range");
    }

    int getSize() const {          // Получение размера массива
        return _size;
    }

    ItemDataArray(const ItemDataArray& a) : _size(a._size), _data(make_unique<T[]>(a._size)) {     // Конструктор копирования
        std::copy_n(a._data.get(), a._size, _data.get());
    }

    ItemDataArray& operator=(const ItemDataArray& a) {        // Оператор присваивания
        if (this != &a) {
            _size = a._size;
            _data = make_unique<T[]>(_size);
            std::copy_n(a._data.get(), _size, _data.get());
        }
        return *this;
    }

    void Erase() {           // удаление массива
        _data.reset();
        _size = 0;
    }

    void Remove(int index)   // удаление элемента
    {
        try
        {
            if (index < 0 || index >= _size)
            {
                throw "Сообщение с таким номером не найдено!";
            }
            if (_size == 1) {
                Erase();
                return;
            }
            unique_ptr<T[]> data = make_unique<T[]>(_size - 1);
            std::copy_n(_data.get(), index, data.get());
            std::copy_n(_data.get() + index + 1, _size - index - 1, data.get() + index);
            _data = move(data);
            --_size;
            cout << "Сообщение удалено!" << endl;
        }
        catch (const char* exception)
        {
            cout << exception << endl;  // вывод на консоль фразы "Сообщение с таким номером не найдено!"
        }
    }
};

// 18.07.2024 by Pavel Kirilenko


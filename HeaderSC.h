#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

using namespace std;

class PersData {          // ����� � ������������� ������� ������������ ����
protected:             
    string persName;     
    string persDirWord;
    string textInfo;
    int messageNum;
public:
    PersData();
    void initPersData(int messageNum);            // ������� ��� ����������� ������������
    string getCharValue(int fieldNumber) const;   // �������-������ ��� ������ ����� ������ ���� string
    int getCharValue() const;                     // �������-������ ��� ������ ���� ������ ���� int
    void setValue(int numValue, string value);    // ������� ������ ��� ������������� ����� ���� string
    void setValue(int value);                     // ������� ������ ��� ������������� ����� ���� int
};

class PersMessage final : public PersData {       // ����� ��������� ������������� - ��������� ������ PersData
public:
    void initPersMessage(string persName, int messageNum);
};

template <typename T>
class ItemDataArray {     // ��������� ����� ��� �������� ������ ������������� � ���������
private:
    int _size;
    unique_ptr<T[]> _data;
public:
    ItemDataArray(int size) : _size(size), _data(make_unique<T[]>(size)) {}
    ~ItemDataArray() = default;

    void setItem(int index, T val) {           // ������ �������� � ������
        if (index >= 0 && index < _size) {
            _data[index] = val;
        }

        unique_ptr<T[]> data = make_unique<T[]>(_size + 1);
        std::copy_n(_data.get(), _size, data.get());
        data[index] = val;
        _data = move(data);
        ++_size;
    }

    T getItem(int index) const {             // ��������� �������� �������
        if (index >= 0 && index < _size) {
            return _data[index];
        }
        throw out_of_range("Index out of range");
    }

    int getSize() const {          // ��������� ������� �������
        return _size;
    }

    ItemDataArray(const ItemDataArray& a) : _size(a._size), _data(make_unique<T[]>(a._size)) {     // ����������� �����������
        std::copy_n(a._data.get(), a._size, _data.get());
    }

    ItemDataArray& operator=(const ItemDataArray& a) {        // �������� ������������
        if (this != &a) {
            _size = a._size;
            _data = make_unique<T[]>(_size);
            std::copy_n(a._data.get(), _size, _data.get());
        }
        return *this;
    }

    void Erase() {           // �������� �������
        _data.reset();
        _size = 0;
    }

    void Remove(int index)   // �������� ��������
    {
        try
        {
            if (index < 0 || index >= _size)
            {
                throw "��������� � ����� ������� �� �������!";
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
            cout << "��������� �������!" << endl;
        }
        catch (const char* exception)
        {
            cout << exception << endl;  // ����� �� ������� ����� "��������� � ����� ������� �� �������!"
        }
    }
};

// 18.07.2024 by Pavel Kirilenko


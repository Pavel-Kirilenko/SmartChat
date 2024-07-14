#pragma once
#include <cassert> // for assert()
#include<iostream>
#include<string>


using namespace std;

class PersData // ����� � ������������� ������� ������������ ����
{
protected:
	string persName;      // ��� ������������
	string persDirWord;  // ������ ������������ (������� ��������� � ������-����������)
	int messageNum;       // ���������� ��������� ������������
public:
	PersData() // ����������� �� ���������
	{
		this->persName = "persName";
		this->persDirWord = "persDirWord";
		this->messageNum = 1;
	}

	PersData(int messageNum) // ����������� ������, ������������ ��� ����������� ������������
	{
        setlocale(LC_ALL, "");                // ������ ��� ����������� ����������� ������������� ��������
        string persName; string persDirWord; // ����������, � ������� ��������� ��� � ������ �������������
        cout << "������� ���� ���: ";
        getline(cin, persName);
        cout << "������� ������: ";
        getline(cin, persDirWord);
        this->persName = persName;
        this->persDirWord = persDirWord;
		this->messageNum = messageNum;
	}

	string getCharValue(int fieldNumber) const // �������-������ ��� ������ ����� ������ ���� string
	{
		return (fieldNumber == 1 ? this->persName : this->persDirWord);
	}

	void setValue(int numValue, string value) // ������� ������ ��� ������������� ����� ���� string
	{
		(numValue == 1 ? this->persName = value : this->persDirWord = value);
	}

	void setValue(int value) // ������� ������ ��� ������������� ����� ���� int
	{
		this->messageNum = value;
	}
};

class PersMessage final : public PersData  // ����� ��������� ������������� - ��������� ������ PersData
{
    string messText;  // ���������� ���������
public:
    PersMessage(string persName)
    {
        string _persDirWord;       // ���� ���������
        string _messText;          // ���������� ���������
        this->persName = persName; // �� ���� ���������
        cout << "���� ��������� ��������� (������� ��� ������������): ";
        getline(cin, _persDirWord);
        this->persDirWord = _persDirWord;
        cout << "������� ����� ���������: ";
        getline(cin, _messText);
        this->messText = _messText;
    }
};

template <typename T>  class ItemDataArray  // ��������� ����� ��� �������� ������ ������������� � ���������
{
private:
	unsigned _size;		// ������ �������
	T* _data;			// ��������� �� ������

public:
    ItemDataArray(unsigned size) // �����������
    {
        _size = size;
        _data = new T[_size];
    }
    ~ItemDataArray() // ����������
    {
        delete[] _data;
    }
    void setItem(int index, T val) // ������ �������� � ������
    {
        if (index >= 0 && index < _size)
            _data[index] = val;

        T* data = new T[_size + 1];      // �������� ������ ������� �� ���� ������� ������ �������������
        std::copy_n(_data, _size, data); // ����������� � ����� ������ ���� ���������
        data[index] = val;               // ������ ������ �������� � ������
        //std::copy_n(_data + index + 1, _size - index - 1, data + index); // ����������� ���� ��������� �� ��������� ���������
        delete[] _data; // �������� ������ ������
        _data = data;
        ++_size; // ���������� ���� ������� ������� �� �������
    }
    T getItem(int index) const // ��������� �������� �������
    {
        if (index >= 0 && index < _size)
            return _data[index];
    }
    unsigned getSize() // ��������� ������� �������
    {
        return _size;
    }
   ItemDataArray(ItemDataArray& a) // ����������� �����������
    {
        _size = a._size; // �������� �������� ���� ������� �������
        _data = new T[_size]; // �������� ������ ��� ������ �������
        for (auto i = 0; i < _size; i++)
            _data[i] = a._data[i]; // �������� �������� �������
    }
    ItemDataArray<T>& operator=(ItemDataArray& a) // �������� ������������
    {
        if (this != &a) { // ���������, ����� �� ��������� ������ ��� � ����, this ��������� �� ������� ������ � ������
            _size = a._size; // �������� �������� ���� ������� �������
            delete[] _data; // ����������� ������ �� ������� �������
            _data = new T[_size]; // �������� ������ � ���� ��� ������ �������
            for (auto i = 0; i < _size; i++)
                _data[i] = a._data[i]; // �������� �������� �������
        }
        return *this; // ���������� ��������� �� ����� ������
    }
    void Erase() // �������� �������
    {
        delete[] _data;
        _data = nullptr;
        _size = 0;
    }
    void Remove(unsigned index) // �������� ��������
    {
        assert(index >= 0 && index < _size); // �������� ��������� �� ��������� ������� � �������� ������� (����������� � ������� throw/catch
        if (_size == 1) // ���� ������ ������� ������ �� ������ ��������, �� �� ���������
        {
            Erase();
            return;
        }
        T* data = new T[_size - 1]; // �������� ������ ������� �� ���� ������� ������ �������������
        std::copy_n(_data, index, data); // ����������� � ����� ������ ���� ��������� �� ������ ���������� ��������
        std::copy_n(_data + index + 1, _size - index - 1, data + index); // ����������� ���� ��������� �� ��������� ���������
        delete[] _data; // �������� ������ ������
        _data = data;
        --_size; // ���������� ���� ������� ������� �� �������
    }
};


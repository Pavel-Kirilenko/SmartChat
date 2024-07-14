#pragma once
#include <cassert> // for assert()
#include<iostream>
#include<string>


using namespace std;

class PersData // ����� � ������������� ������� ������������ ����
{
	string persName;      // ��� ������������
	string persPassword;  // ������ ������������
	int messageNum;       // ���������� ��������� ������������
public:
	PersData() // ����������� �� ���������
	{
		this->persName = "persName";
		this->persPassword = "persPassword";
		this->messageNum = 1;
	}

	PersData(int messageNum) // ����������� ������, ������������ ��� ����������� ������������
	{
        setlocale(LC_ALL, "");                // ������ ��� ����������� ����������� ������������� ��������
        string persName; string persPassword; // ����������, � ������� ��������� ��� � ������ �������������
        cout << "������� ���� ���: ";
        getline(cin, persName);
        cout << "������� ������: ";
        getline(cin, persPassword);
        this->persName = persName;
        this->persPassword = persPassword;
		this->messageNum = messageNum;
	}

	string getCharValue(int fieldNumber) const // �������-������ ��� ������ ����� ������ ���� string
	{
		return (fieldNumber == 1 ? this->persName : this->persPassword);
	}

	void setValue(int numValue, string value) // ������� ������ ��� ������������� ����� ���� string
	{
		(numValue == 1 ? this->persName = value : this->persPassword = value);
	}

	void setValue(int value) // ������� ������ ��� ������������� ����� ���� int
	{
		this->messageNum = value;
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


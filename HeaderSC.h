#pragma once
#include <cassert> // for assert()

class PersData // ����� � ������������� ������� ������������ ����
{
	const char* persName;     // ��� ������������
	const char* persPassword;  // ������ ������������
	int messageNum;       // ���������� ��������� ������������
public:
	PersData() // ����������� �� ���������
	{
		this->persName = "persName";
		this->persPassword = "persPassword";
		this->messageNum = 1;
	}

	PersData(const char* persName, const char* persPassword, int messageNum) // ����������� ������, ������������ ��� ����������� ������������
	{
		this->persName = persName;
		this->persPassword = persPassword;
		this->messageNum = messageNum;
	}

	const char* getCharValue(int fieldNumber) const // �������-������ ��� ������ ����� ������ ���� const char*
	{
		return (fieldNumber == 1 ? this->persName : this->persPassword);
	}

	void setValue(int numValue, const char* value) // ������� ������ ��� ������������� ����� ���� const char*
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


#include "HeaderSC.h"
#include <iostream>
#include <cassert>    // for assert()

using namespace std;
PersData::PersData()  // ����������� �� ���������
{
	this->persName = "persName";
	this->persPassword = "persPassword";
	this->messageNum = 1;
}
PersData::PersData(string persName, string persPassword, int messageNum)  // ����������� ������, ������������ ��� ����������� ������������
{
	this->persName = persName;
	this->persPassword = persPassword;
	this->messageNum = messageNum;
}


PersDataArray::PersDataArray(int _persNumber) : // ����������� ����������
	persNumber{ _persNumber }                   // ��� �������� ������������� ����
{
	assert(_persNumber >= 0);   // �������� �������������� ���������� ���������� � ������� throw/catch
	if (_persNumber > 0) person = new PersData[_persNumber]{};
}
PersDataArray::~PersDataArray()  // ����������
{
	delete[] person;
}
void PersDataArray::Erase()                     // ������� �������� �������
{
	person = nullptr;
	persNumber = 0;
}
PersData& PersDataArray::operator[](int index)  // ������� ������� � �������� ������� �� �������
{
	assert(index >= 0 && index < persNumber);   // �������� �������������� ���������� ���������� � ������� throw/catch
	return person[index];
}
int PersDataArray::getLenght() const            // �������-������ ����������� ����� �������
{
	return persNumber;
}
void PersDataArray::InsertBefore(PersData value, int index) // ������� �������� ����� ������ ��������� � ��������� ��������
{
	assert(index >= 0 && index <= persNumber); // �������� �������������� ���������� ���������� � ������� throw/catch
	PersData* data{ new PersData[persNumber + 1] };      // �������� ������ ������� �� ������� ������� �����������
	copy_n(person, index, data);               // ����������� ���� ��������� �� �������
	data[index] = value;                       // ���������� ������ �������� � ������
	copy_n(person + index, persNumber - index, data + index + 1); // ����������� ���� ��������� ����� �������
	delete[] person;       // �������� ������� ������� � ������������� ������ ������
	person = data;
	++persNumber;
}
void PersDataArray::Remove(int index)            // ������� �������� �������� � ��������� ��������
{
	assert(index >= 0 && index < persNumber); // �������� �������������� ���������� ���������� � ������� throw/catch
	if (persNumber == 1)            // ���� � ������� ����� ���� �������, �� ������ ���������
	{
		Erase();
		return;
	}
	PersData* data{ new PersData[persNumber - 1] }; // �������� ������ ������� � ������ �� ���� ������� ������
	copy_n(person, index, data);     // ����������� ���� ��������� �� �������
	copy_n(person + index + 1, persNumber - index - 1, data + index); // ����������� ���� ��������� ����� �������
	delete[] person;  // �������� ������� ������� � �������� ������
	person = data;
	--persNumber;
}

#include "HeaderSC.h"
#include <iostream>
#include <cassert>    // for assert()

using namespace std;

PersData::PersData()  // ����������� ������, ������������ ��� ����������� ������������
{
	string persName = "A";      // ������������� ��������� ���������� � ������� ����� �������� ��� ������������
	string persPassword = "B";  // ������������� ��������� ���������� � ������� ����� ������� ������ ������������
	cout << "������� ���� ���:" << endl;  // ���� ����� ������������
	cin >> persName;
	cout << "������� ������:" << endl;
	cin >> persPassword;                  // ���� ������ ������������
	this->persName = persName;
	this->persPassword = persPassword;
}


PersDataArray::PersDataArray(int _persNumber) : // ����������� ����������
	persNumber{ _persNumber }   // ��� �������� ������������� ����
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
#include "HeaderSC.h"
#include <iostream>

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
	// ����� ���� ����� ������� ����������, ���� ���������� ������������� ������ ����
	if (_persNumber > 0) person = new PersData[_persNumber]{};
}
PersDataArray::~PersDataArray()  // ����������
{
	delete[] person;
}
PersData& PersDataArray::operator[](int index)  // ������� ������� � �������� ������� �� �������
{
	// ����� ���������� ����� ������� ����������, ���� ������ ������� �� ������� �������
	return person[index];
}
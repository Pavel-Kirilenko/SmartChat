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
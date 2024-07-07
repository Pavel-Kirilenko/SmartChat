#pragma once
#include<string>

using namespace std;

class PersData // ����� � ������������� ������� ������������ ����
{
	string persName;     // ��� ������������ 
	string persPassword;  // ������ ������������
	int messageNum;       // ���������� ��������� ������������
public:
	PersData(); // ����������� ������, ������� ������������ ��� ����������� ������������
};
class PersDataArray // �����-��������� ��� �������� ������������� ���� � ��
	// � �� ������������� �������
{
	int persNumber;   // ���������� ������������� � ����� �������
	PersData* person; // ��������� �� ������ ������� � ������� �������������
public:
	PersDataArray(int _persNumber);
	~PersDataArray();                 // ���������� ��� ������������ ����������� ���������� ������
	PersData& operator[](int index);  // ������� ������� � �������� ������� �� �������
};
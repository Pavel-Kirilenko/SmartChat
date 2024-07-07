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
	PersDataArray() = default;        // �� ��������� ���������� ���� ��� �������� �������������
	PersDataArray(int _persNumber);
	~PersDataArray();                 // ���������� ��� ������������ ����������� ���������� ������
	void Erase();                     // ������� �������� �������
	PersData& operator[](int index);  // ������� ������� � �������� ������� �� �������
	int getLenght() const;            // �������-������ ����������� ����� �������
};
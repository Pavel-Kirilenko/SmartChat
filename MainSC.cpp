#include<iostream>
#include"HeaderSC.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	PersData user; // ������������� ������ ������������
	PersDataArray arrayData(2);  // �������� ������� ��� ��������� ������������� �� ������ ���������
	arrayData[1] = user;
	return 0;
}
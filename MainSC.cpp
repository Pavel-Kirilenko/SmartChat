#include<iostream>
#include"HeaderSC.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	PersDataArray arrayData(4);  // �������� ������� ��� ��������� ������������� �� ������ ���������
	//cout << arrayData.getLenght;
	//arrayData.Erase();
	//PersData person = arrayData[0];
	arrayData.Remove(3);
	PersData Person;
	arrayData.InsertBefore(Person, 3);

	return 0;
}
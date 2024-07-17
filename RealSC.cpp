#include"HeaderSC.h"

PersData::PersData() // ����������� �� ���������
{
	this->persName = "persName";
	this->persDirWord = "persDirWord";
	this->textInfo = "textInfo";
	this->messageNum = 0;
}
void PersData::initPersData(int messageNum)  // ������� ��� ����������� ������������
{
    string persName; string persDirWord;     // ����������, � ������� �������� ��� � ������ �������������
    cout << "������� ���� ���: ";
    getline(cin, persName);
    cout << "������� ������: ";
    getline(cin, persDirWord);
    this->persName = persName;
    this->persDirWord = persDirWord;
    this->messageNum = messageNum;
}
string PersData::getCharValue(int fieldNumber) const // �������-������ ��� ������ ����� ������ ���� string
{
    switch (fieldNumber)
    {
    case 1: return this->persName; break;
    case 2: return this->persDirWord; break;
    case 3: return this->textInfo;
    }
}
int PersData::getCharValue() const // �������-������ ��� ������ ���� ������ ���� int
{
    return this->messageNum;
}
void PersData::setValue(int numValue, string value) // ������� ������ ��� ������������� ����� ���� string
{
    (numValue == 1 ? this->persName = value : this->persDirWord = value);
}
void PersData::setValue(int value) // ������� ������ ��� ������������� ����� ���� int
{
    this->messageNum = value;
}
void PersMessage::initPersMessage(string persName, int messageNum)  //  ������� �������� ���������
{
    string _persDirWord;            // ���� ���������
    string _textInfo;               // ���������� ���������
    this->persName = persName;      // �� ���� ���������
    this->messageNum = messageNum;  // ���������� ����� ���������
    cout << "���� ��������� ��������� (������� ��� ������������ ��� '����'): ";
    getline(cin, _persDirWord);
    this->persDirWord = _persDirWord;
    cout << "������� ����� ���������: ";
    getline(cin, _textInfo);
    this->textInfo = _textInfo;
}
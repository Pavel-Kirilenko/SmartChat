#include"HeaderSC.h"

PersData::PersData() // конструктор по умолчанию
{
	this->persName = "persName";
	this->persDirWord = "persDirWord";
	this->textInfo = "textInfo";
	this->messageNum = 0;
}
void PersData::initPersData(int messageNum)  // функция для регистрации пользователя
{
    string persName; string persDirWord;     // переменные, в которых хранятся имя и пароль пользователей
    cout << "Введите ваше имя: ";
    getline(cin, persName);
    cout << "Введите пароль: ";
    getline(cin, persDirWord);
    this->persName = persName;
    this->persDirWord = persDirWord;
    this->messageNum = messageNum;
}
string PersData::getCharValue(int fieldNumber) const // функция-геттер для вывода полей класса типа string
{
    switch (fieldNumber)
    {
    case 1: return this->persName; break;
    case 2: return this->persDirWord; break;
    case 3: return this->textInfo;
    }
}
int PersData::getCharValue() const // функция-геттер для вывода поля класса типа int
{
    return this->messageNum;
}
void PersData::setValue(int numValue, string value) // функция сеттер для инициализации полей типа string
{
    (numValue == 1 ? this->persName = value : this->persDirWord = value);
}
void PersData::setValue(int value) // функция сеттер для инициализации полей типа int
{
    this->messageNum = value;
}
void PersMessage::initPersMessage(string persName, int messageNum)  //  функция создания сообщения
{
    string _persDirWord;            // кому сообщение
    string _textInfo;               // содержание сообщения
    this->persName = persName;      // от кого сообщение
    this->messageNum = messageNum;  // порядковый номер сообщения
    cout << "Кому отправить сообщение (введите имя пользователя или 'всем'): ";
    getline(cin, _persDirWord);
    this->persDirWord = _persDirWord;
    cout << "Введите текст сообщения: ";
    getline(cin, _textInfo);
    this->textInfo = _textInfo;
}
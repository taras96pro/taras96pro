#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <Windows.h>

using namespace std;

class Device
{
public:
	Device(const char* set_Model)
	{
		Model = new char[strlen(set_Model) + 1];
		strcpy(Model, set_Model);
		Name = 0;
	}
	virtual ~Device()
	{
		if (Name != 0)
		{
			delete[] Name;
		}
		if (Model != 0)
		{
			delete[] Model;
		}
	}
	virtual char* Mode() = 0;
	virtual void setMode(bool k) = 0;
	virtual bool Status()
	{
		return IsWork;
	}
public:
	char* Name;
	char* Model;
	bool IsWork = 0;
};

class VideoPlayer : public Device
{
public:
	VideoPlayer(const char* set_Model, const char* set_Name, int memory, int screenW, int screenH) : Device(set_Model)
	{
		IsWork = 0;
		Name = new char[strlen(set_Name) + 1];
		strcpy(Name, set_Name);
		this->Memory = memory;
		this->screen[0] = screenW;
		this->screen[1] = screenH;
	}
	virtual ~VideoPlayer()
	{

	}
	virtual char* Mode()
	{
		char* curMode = new char[20];
		if (mode == 0)
		{
			strcpy(curMode, "Пауза");
		}
		else
		{
			strcpy(curMode, "Відтворення");
		}
		return curMode;
	}
	virtual void setMode(bool k)
	{
		mode = k;
	}
	virtual int Get_Memory()
	{
		return Memory;
	}
private:
	int Memory = 0;
	int screen[2];
	bool mode = 0;
};



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	VideoPlayer Player("Samsung", "Player1", 1024, 1366, 720);
	Player.setMode(1);
	cout << "Модель: " << Player.Model << endl;
	cout << "Ім'я: " << Player.Name << endl;
	cout << "Кількість пам'яті: " << Player.Get_Memory() << endl;
	cout << "Поточний режим: " << Player.Mode() << endl;
	system("pause");
	return 0;
}
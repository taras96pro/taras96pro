#include <iostream>
#include <iomanip>
#include <Windows.h>

#define w 10

using namespace std;

class CDevice
{
protected:
	int year;
	char* manufacturer, *material;
public:
	CDevice(const char* manufacturer, const char* material, int year)
	{
		setInfo(manufacturer, material, year);
	}
	~CDevice()
	{
		delete[] manufacturer;
		delete[] material;
	}
	void setInfo(const char* manufacturer, const char* material, int year)
	{
		this->manufacturer = new char[strlen(manufacturer) + 1];
		strcpy_s(this->manufacturer, strlen(manufacturer) + 1, manufacturer);
		this->material = new char[strlen(material) + 1];
		strcpy_s(this->material, strlen(material) + 1, material);
		this->year = year;
	}
	virtual void PrintInfo() = 0;
};

class CClock : public CDevice
{
protected:
	struct hourS {
		int hour, minute, second;
	} hour;
public:
	CClock(const char* manufacturer, const char* material, int year, int hour, int minute, int second) : CDevice(manufacturer, material, year)
	{
		setInfo(hour, minute, second);
	}
	void setInfo(int hour, int minute, int second)
	{
		this->hour.hour = hour;
		this->hour.minute = minute;
		this->hour.second = second;
	}
	virtual void PrintInfo()
	{
		cout << "Clock info:" << endl;
		cout << setw(w) << left << "Виробник: " << CDevice::manufacturer << endl;
		cout << setw(w) << left << "Матеріал: " << CDevice::material << endl;
		cout << setw(w) << left << "Рік виготовлення: " << CDevice::year << endl;
		cout << setw(w) << left << "Поточний час: " << hour.hour << ":" << hour.minute << ":" << hour.second << endl;
	}
};

class CCuckoo : public CDevice
{
protected:
	char* kind;
public:
	CCuckoo(const char* manufacturer, const char* material, int year, const char* kind) : CDevice(manufacturer, material, year)
	{
		setInfo(kind);
	}
	void setInfo(const char* kind)
	{
		this->kind = new char[strlen(kind) + 1];
		strcpy_s(this->kind, strlen(kind) + 1, kind);
	}
	virtual void PrintInfo()
	{
		cout << "Cuckoo info:" << endl;
		cout << setw(w) << left << "Виробник: " << CDevice::manufacturer << endl;
		cout << setw(w) << left << "Матеріал: " << CDevice::material << endl;
		cout << setw(w) << left << "Рік виготовлення: " << CDevice::year << endl;
		cout << setw(w) << left << "Вид: " << kind << endl;
	}
};

class CCuckooClock : public CClock, public CCuckoo
{
public:
	CCuckooClock(const char* manufacturer, const char* material, int year, int hour, int minute, int second, const char* kind) : CClock(manufacturer, material, year, hour, minute, second), CCuckoo(manufacturer, material, year, kind)
	{

	}
	virtual void PrintInfo()
	{
		cout << "CuckooClock info:" << endl;
		cout << setw(w) << left << "Виробник: " << CDevice::manufacturer << endl;
		cout << setw(w) << left << "Матеріал: " << CDevice::material << endl;
		cout << setw(w) << left << "Рік виготовлення: " << CDevice::year << endl;
		cout << setw(w) << left << "Поточний час: " << CClock::hour.hour << ":" << CClock::hour.minute << ":" << CClock::hour.second << endl;
		cout << setw(w) << left << "Вид пташки: " << CCuckoo::kind << endl;
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	CClock Clock1("Goodoo", "Дерево", 1995, 15, 53, 20);
	Clock1.PrintInfo();

	cout << endl << endl;

	CCuckoo Cuckoo1("Marji", "Натуральне пір'я", 2005, "Синиця");
	Cuckoo1.PrintInfo();

	cout << endl << endl;

	CCuckooClock CuckooClock1("Goodoo", "Дерево", 2003, 10, 13, 20, "Ластівка");
	CuckooClock1.PrintInfo();

	cout << endl;
	system("pause");
	return 0;
}
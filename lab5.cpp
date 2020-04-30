#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

class CLake
{
private:
	int area,
		volume,
		depth,
		evaporation;
public:
	CLake(int area, int volume, int depth, int evaporation)
	{
		setstate(area, volume, depth, evaporation);
	}
	void fill(int amount)
	{
		volume += amount;
	}
	void dryingTime()
	{
		cout << "��� �������������: " << volume / evaporation << endl;
	}
	void setstate(int area, int volume, int depth, int evaporation)
	{
		this->area = area;
		this->volume = volume;
		this->depth = depth;
		this->evaporation = evaporation;
	}
	void currentstate()
	{
		cout << "�����: " << area << endl;
		cout << "��'�� ����: " << volume << endl;
		cout << "�������: " << depth << endl;
		cout << "�������� �������������: " << evaporation << endl;
	}
	CLake operator + (const CLake& Lake)
	{
		area = area + Lake.area;
		volume = volume + Lake.volume;
		depth = depth + Lake.depth;
		evaporation = evaporation + Lake.evaporation;
		return *this;
	}
	CLake& operator -= (const CLake& Lake)
	{
		area -= Lake.area;
		volume -= Lake.volume;
		depth -= Lake.depth;
		evaporation -= Lake.evaporation;
		return *this;
	}
	bool operator < (CLake& Lake)
	{
		return volume < Lake.volume;
	};
	bool operator > (CLake& Lake)
	{
		return volume > Lake.volume;
	};
	friend ostream& operator << (ostream& os, const CLake& Lake) {
		cout << "�����: " << Lake.area << endl;
		cout << "��'�� ����: " << Lake.volume << endl;
		cout << "�������: " << Lake.depth << endl;
		cout << "�������� �������������: " << Lake.evaporation << endl;
		os << endl;
		return os;
	}
	friend istream& operator >> (istream& is, CLake& Lake) {
		cout << "������ �����: " << endl;
		is >> Lake.area;
		cout << "������ ��'�� ����: " << endl;
		cin >> Lake.volume;
		cout << "������ �������: " << endl;
		is >> Lake.depth;
		cout << "������ �������� ������������� ����: " << endl;
		is >> Lake.evaporation;
		return is;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	CLake Lake1(100, 700, 10, 15), Lake2(600, 4000, 50, 90);
	cout << "�����1: " << endl; cout << Lake1 << endl;
	cout << endl;
	Lake1 = Lake1 + Lake2;
	cout << endl;
	cout << "�����1: " << endl; cout << Lake1 << endl;
	cout << endl;
	cout << "�����1: " << endl; Lake1.dryingTime();
	cout << endl;
	cout << endl;

	cout << "�����2: " << endl; cout << Lake2 << endl;
	cout << endl;
	cout << "�����2: " << endl; Lake2.dryingTime();
	cout << endl;
	int k = Lake1 < Lake2;
	cout << "�����1 < �����2: " << k << endl;
	cout << endl;
	k = Lake1 > Lake2;
	cout << "�����1 > �����2: " << k << endl;
	system("pause");
	return 0;
}
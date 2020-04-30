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
		CLake(int area,	int volume,	int depth, int evaporation)
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
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	CLake Lake(500, 700, 20, 30);
	Lake.currentstate();
	Lake.fill(50);
	cout << endl;
	Lake.currentstate();	
	cout << endl;
	Lake.dryingTime();
	system("pause");
	return 0;
}
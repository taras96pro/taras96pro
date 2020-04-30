#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

template <typename type>
class Matrix
{
private:
	int x, y;
	type** Arr;
	int size_x, size_y;
public:
	Matrix() {

	}
	Matrix(int size_x, int size_y)
	{
		this->size_x = size_x;
		this->size_y = size_y;
		Arr = new type * [size_x];
		for (int i = 0; i < size_x; i++) 
		{
			Arr[i] = new type[size_y];
			for (int j = 0; j < size_y; j++) 
			{
				Arr[i][j] = 0;
			}
		}
	}
	void create(int size_x, int size_y)
	{
		Arr = new type * [size_x];
		for (int i = 0; i < size_x; i++)
		{
			Arr[i] = new type[size_y];
			for (int j = 0; j < size_y; j++)
			{
				Arr[i][j] = 0;
			}
		}
	}
	~Matrix()
	{
		for (int i = 0; i < size_x; i++)
		{
			delete Arr[i];
		}
		delete[] Arr;
	}
	friend ostream& operator<<(ostream& output, Matrix<type>& matr) 
	{ 
		for (int i = 0; i < matr.size_x; i++) 
		{ 
			for (int j = 0; j < matr.size_y; j++) 
			{ 
				output << matr.Arr[i][j] << "\t"; 
			}
			output << endl << endl;
		}
		output << endl;
		return output; 
	}
	friend istream& operator>>(istream& is, Matrix<type>& matr) 
	{
		matr.~Matrix();
		cout << "Введіть кількість рядків: "; 
		is >> matr.size_x;
		cout << "Введіть кількість стовпців: ";
		is >> matr.size_y;
		matr.Arr = new type * [matr.size_x];
		cout << "Для рандомного заповнення введіть - 1\nДля ручного заповнення введіть - 2\n";
		matr.create(matr.size_x, matr.size_y);
		int l = 1; 
		cin >> l; 
		switch (l)
		{
		case 1:
			for (int i = 0; i < matr.size_x; i++)
			{
				for (int j = 0; j < matr.size_y; j++)
				{
					matr.Arr[i][j] = rand() % 99;
				}
			}
			break;
		case 2:
			for (int i = 0; i < matr.size_x; i++)
			{
				for (int j = 0; j < matr.size_y; j++)
				{
					cout << "a[" << i << "]" << "[" << j << "]" << "=";
					is >> matr.Arr[i][j];
				}
			}
			break;
			return is;
		}
	}
	int search()
	{
		int sum = 0;
		for (int i = 0; i < size_x; i++)
		{
			for (int j = 0; j < size_y; j++)
			{
				if (i % 2 != 0 && j % 2 == 0)
				{
					cout << "a[" << i << "]" << "[" << j << "]" << "=";
					cout << Arr[i][j] << endl;
					sum += Arr[i][j];
				}
			}
		}
		return sum;
	}
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	Matrix<int> Arr(10, 10);

	cin >> Arr;
	cout << endl << Arr;

	cout << endl << "Sum = " << Arr.search() << endl;
	system("pause");
	return 0;
}
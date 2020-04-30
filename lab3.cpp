#include <iostream>
#include <iomanip>

using namespace std;

void func(int** arr, int n)
{
	for (int i = 0; i < 4 * n; i++)
	{
		for (int j = 0; j < 4 * n; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < 4 * n; i++)
	{
		for (int j = 0; j < 4 * n; j++)
		{
			if (i >= n && i < 3 * n && j >= n && j < 3 * n)
			{
				arr[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < 4 * n; i++)
	{
		for (int j = 0; j < 4 * n; j++)
		{
			cout << setw(2) << arr[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	int** arr = new int* [4 * n];
	for (int i = 0; i < 4 * n; i++)
	{
		arr[i] = new int[4 * n];
	}
	func(arr, n);
	for (int i = 0; i < 4 * n; i++)
	{
		delete arr[i];
	}
	system("pause");
	return 0;
}
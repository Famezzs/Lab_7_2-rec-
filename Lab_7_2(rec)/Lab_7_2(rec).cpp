// Lab_7_2(rec).cpp
// Козубенко Андрій
// Лабораторна робота № 7.2
// Опрацювання багатовимірних масивів ітераційним і рекурсивним способами.
// Варіант 10
// Рекурсивний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::setw;

void Create(int **a, const int rowCount, const int colCount, const int Low, const int High, const int rowNo, const int colNo);
void Print(int **a, const int rowCount, const int colCount, const int rowNo, const int colNo);
void SumOddColMax(int **a, const int rowCount, const int colCount, int &S, const int rowNo, const int colNo, const int z);
void Max(int **a, const int rowCount, const int colNo, const int i, int &max);

int main()
{
	srand((unsigned)time(NULL));
	int Low;
	int High;
	int rowCount;
	int colCount;
	int S = 0;

	cout << "How many rows should a new matrix consist of?\n  k = "; cin >> rowCount;
	if (rowCount < 1)
	{
		cerr << "Amount of rows should be >= 1";
		return -1;
	}

	cout << "How many columns should a new matrix consist of?\n  n = "; cin >> colCount;
	if (colCount < 1)
	{
		cerr << "Amount of columns should be >= 1";
		return -1;
	}

	cout << "What interval should RNG satisfy? (i.e. [A;B], A <= B)\n  A = "; cin >> Low;
	cout << "  B = "; cin >> High;
	if (Low > High)
	{
		cerr << "A should be <= B";
		return -1;
	}

	int **Q = new int *[rowCount];
	for (int row = 0; row < rowCount; row++)
		Q[row] = new int[colCount];

	Create(Q, rowCount, colCount, Low, High, 0, 0);
	cout << endl;
	Print(Q, rowCount, colCount, 0, 0);
	SumOddColMax(Q, rowCount, colCount, S, 0, 0, 0);

	cout << "Sum of maximal elements in odd columns = " << S << endl;

	for (int row = 0; row < rowCount; row++)
		delete[] Q[row];
	delete[] Q;

	return 0;
}

void Create(int **a, const int rowCount, const int colCount, const int Low, const int High, const int rowNo, const int colNo)
{
	if (rowNo < rowCount)
	{
		if (colNo < colCount)
		{
			a[rowNo][colNo] = Low + rand() % (High - Low + 1);
			Create(a, rowCount, colCount, Low, High, rowNo, colNo + 1);
		}
		Create(a, rowCount, colCount, Low, High, rowNo + 1, 0);
	}
}

void Print(int **a, const int rowCount, const int colCount, const int rowNo, const int colNo)
{
	if (rowNo < rowCount)
	{
		if (colNo < colCount)
		{
			cout << setw(4) << a[rowNo][colNo];
			Print(a, rowCount, colCount, rowNo, colNo + 1);
		}
		else
		{
			cout << endl;
			Print(a, rowCount, colCount, rowNo + 1, 0);
		}
	}
	else
		cout << endl;
}

void SumOddColMax(int **a, const int rowCount, const int colCount, int &S, const int rowNo, const int colNo, const int z)
{
	if (z < colCount / 2.)
	{
		int max = a[0][colNo];
		Max(a, rowCount, colNo, 0, max);

		S += max;
		SumOddColMax(a, rowCount, colCount, S, 0, colNo + 2, z + 1);
	}
}

void Max(int **a, const int rowCount, const int colNo, const int i, int &max)
{
	if (i < rowCount)
	{
		if (a[i][colNo] > max)
			max = a[i][colNo];
		Max(a, rowCount, colNo, i + 1, max);
	}
}
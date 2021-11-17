#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Home\source\repos\Lab_7_2(rec)\Lab_7_2(rec)\Lab_7_2(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
	TEST_CLASS(UnitTest72rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int S = 0;
			const int rowCount = 2;
			const int colCount = 7;

			int **Z = new int *[rowCount];
			for (int row = 0; row < rowCount; row++)
				Z[row] = new int[colCount];

			for (int row = 0; row < rowCount; row++)
			{
				if (row == 0)
					for (int col = 0; col < colCount; col++)
						Z[row][col] = 1;
				else
					for (int col = 0; col < colCount; col++)
						Z[row][col] = 2;
			}

			SumOddColMax(Z, rowCount, colCount, S, 0, 0);

			Assert::AreEqual(S, 8);

			for (int row = 0; row < rowCount; row++)
				delete[] Z[row];
			delete[] Z;
		}
	};
}

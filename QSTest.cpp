#include "QSTest.h"
using namespace std;

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))


QSTest::QSTest()
{
	TestBit = true; // true if testing and cout comments are desired, false otherwise
}


QSTest::~QSTest()
{
}

/*
* testSortAll
*
* Returns true if the given QSInterface object correctly sorts given arrays.
*
* @param test
* 		an implementation of the QSInterface class
* @return
* 		true if [test] correctly sorts; false otherwise
*/
bool QSTest::testSortAll(QSInterface* test)
{


	// TEST 1 - sort and a double
	int testArray1[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray1Result[6] = { 0, 2, 4, 5, 7, 7 };

	print(TestBit, testArray1); // print out before test
	test->sortAll(testArray1, 6);  // sort using test's sort all 
	print(TestBit, testArray1); // print out after test

	for (int x = 0; x < ARRAY_SIZE(testArray1); x++)  // check if expected result return false if not what expected
	{
		if (testArray1[x] != testArray1Result[x])
		{
			return false;
		}
	}
	if (TestBit)
	{
		cout <<  "sortAll Passed TEST 1 - sort and a double"<< endl;
	}


	// TEST 2  - size zero
	int testArray2[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray2Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told size is zero

	print(TestBit, testArray2);
	test->sortAll(testArray2, 0);
	print(TestBit, testArray2);

	for (int x = 0; x < ARRAY_SIZE(testArray2); x++)  // check if expected result return false if not what expected
	{
		if (testArray2[x] != testArray2Result[x])
		{
			return false;
		}
	}
	if (TestBit)
	{
		cout << "sortAll Passed TEST 2  - size zero"<<endl;
	}



	return true; // if all tests passed return true
}

/*
* testSort
*
* Returns true if the given QSInterface object correctly sorts given subarrays.
*
* @param test
* 		an implementation of the QSInterface class
* @return
* 		true if [test] correctly sorts; false otherwise
*/
bool QSTest::testSort(QSInterface* test)
{


	// TEST 1 - sort all using sort
	int testArray1[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray1Result[6] = { 0, 2, 4, 5, 7, 7 };

	print(TestBit, testArray1); // print out before test
	test->sort(testArray1,6,0,5);  // sort using test's sort all 
	print(TestBit, testArray1); // print out after test

	for (int x = 0; x < ARRAY_SIZE(testArray1); x++)  // check if expected result return false if not what expected
	{
		if (testArray1[x] != testArray1Result[x])
		{
			return false;
		}
	}
	if (TestBit)
	{
		cout << "sort Passed TEST 1 - sort all using sort"<< endl;
	}


	// TEST 2  - size zero
	int testArray2[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray2Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told size is zero

	print(TestBit, testArray2);
	test->sort(testArray1, 0, 0, 5); // given size zero
	print(TestBit, testArray2);

	for (int x = 0; x < ARRAY_SIZE(testArray2); x++)  // check if expected result return false if not what expected
	{
		if (testArray2[x] != testArray2Result[x])
		{
			return false;
		}
	}
	if (TestBit)
	{
		cout << "sort Passed TEST 2  - size zero"<< endl;
	}

	// TEST 3  - first integer is not less than the second integer
	int testArray3[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray3Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told bad boundries

	print(TestBit, testArray3);
	test->sort(testArray1, 6, 4, 1);
	print(TestBit, testArray3);

	for (int x = 0; x < ARRAY_SIZE(testArray3); x++)  // check if expected result return false if not what expected
	{
		if (testArray3[x] != testArray3Result[x])
		{
			return false;
		}
	}
	if (TestBit)
	{
		cout << "sort Passed TEST 3  - first integer is not less than the second integer" << endl;
	}

	// TEST 4  - out of bounds left
	int testArray4[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray4Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told bad boundries

	print(TestBit, testArray4);
	test->sort(testArray1, 6, -2, 5);
	print(TestBit, testArray4);

	for (int x = 0; x < ARRAY_SIZE(testArray4); x++)  // check if expected result return false if not what expected
	{
		if (testArray4[x] != testArray4Result[x])
		{
			return false;
		}
	}
	if (TestBit)
	{
		cout << "sort Passed TEST 4  - out of bounds left" << endl;
	}

	// TEST 5  - out of bounds right
	int testArray5[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray5Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told bad boundries

	print(TestBit, testArray5);
	test->sort(testArray1, 6, 2, 7);
	print(TestBit, testArray5);

	for (int x = 0; x < ARRAY_SIZE(testArray5); x++)  // check if expected result return false if not what expected
	{
		if (testArray5[x] != testArray5Result[x])
		{
			return false;
		}
	}
	if (TestBit)
	{
		cout << "sort Passed TEST 5  - out of bounds right" << endl;
	}

	// TEST 6 - sort portion 1:3
	int testArray1[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray1Result[6] = { 4, 2, 5, 7, 0, 7 }; // 1 through 3 are sorted

	print(TestBit, testArray1); // print out before test
	test->sort(testArray1, 6, 1, 3);  // sort using test's sort all 
	print(TestBit, testArray1); // print out after test

	if (testArray1[1] != testArray1Result[1]) // check if expected result return false if not what expected
	{
		return false;
	}
	if (testArray1[2] != testArray1Result[2]) // check if expected result return false if not what expected
	{
		return false;
	}
	if (testArray1[3] != testArray1Result[3]) // check if expected result return false if not what expected
	{
		return false;
	} 
	if (TestBit)
	{
		cout << "sort Passed TEST 6 - sort portion 1:3" << endl;
	}

	return true; // if all tests passed return true
}

/*
* testMedianOfThree
*
* Returns true if the given QSInterface object correctly performs median-of-three pivot selection.
*
* @param test
* 		an implementation of the QSInterface class
* @return
* 		true if [test] correctly selects a pivot; false otherwise
*/
bool QSTest::testMedianOfThree(QSInterface* test)
{
}

/*
* testPartition
*
* Returns true if the given QSInterface object correctly partitions.
*
* @param test
* 		an implementation of the QSInterface class
* @return
* 		true if [test] correctly partitions; false otherwise
*/
bool QSTest::testPartition(QSInterface* test)
{
}

/*
* testSwap
*
* Returns true if the given QSInterface object correctly swaps elements.
*
* @param test
* 		an implementation of the QSInterface class
* @return
* 		true if [test] correctly swaps elements = 0; false otherwise
*/
bool QSTest::testSwap(QSInterface* test)
{
}

void QSTest::print(bool TestBit, int array[])
{
	if (TestBit)
	{
		for (int x = 0; x < ARRAY_SIZE(array); x++)
		{
			if (x == 0)
			{
				cout << "Here is the array : " << array[x];
			}
			else
			{
				if (x == (ARRAY_SIZE(array) - 1))
				{
					cout << ", " << array[x] << endl;
				}
				else
				{
					cout << ", " << array[x];
				}
			}
		}
}
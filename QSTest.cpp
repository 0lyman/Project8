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
		cout <<  "sortAll Passed TEST 1 of 2 - sort and a double"<< endl;
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
		cout << "sortAll Passed TEST 2 of 2  - size zero"<<endl;
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
		cout << "sort Passed TEST 1 of 6 - sort all using sort"<< endl;
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
		cout << "sort Passed TEST 2 of 6  - size zero"<< endl;
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
		cout << "sort Passed TEST 3 of 6  - first integer is not less than the second integer" << endl;
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
		cout << "sort Passed TEST 4 of 6  - out of bounds left" << endl;
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
		cout << "sort Passed TEST 5 of 6  - out of bounds right" << endl;
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
		cout << "sort Passed TEST 6 of 6 - sort portion 1:3" << endl;
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
/*
* After this method is called,
* data[first] <= data[middle] <= data[last], where middle =
* (first + last)/2.
*
* Does nothing if the given array is empty, if either of the given integers
* is out of bounds, or if the first integer is not less than the second
* integer.
*/

	// TEST 1 - Median of Three, even number of objects in array
	int testArray1[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray1Result[6] = { 2, 7, 4, 5, 0, 7 };

	print(TestBit, testArray1); // print out before test
	test->medianOfThree(testArray1, 6, 0, 5);  // sort using test's sort all 
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
		cout << "MOT: Passed TEST 1 of 6 - Median of Three, even number of objects in array" << endl;
	}

	// TEST 2 - Median of Three, odd number of objects in array
	int testArray[6] = { 4, 7, 0, 5, 2, 7 };
	int testArrayResult[6] = { 0, 7, 2, 5, 4, 7 };

	print(TestBit, testArray); // print out before test
	test->medianOfThree(testArray, 5, 0, 4);  // sort using test's sort all 
	print(TestBit, testArray); // print out after test

	for (int x = 0; x < ARRAY_SIZE(testArray); x++)  // check if expected result return false if not what expected
	{
		if (testArray[x] != testArrayResult[x])
		{
			return false;
		}
	}
	if (TestBit)
	{
		cout << "MOT: Passed TEST 2 of 6 - Median of Three, odd number of objects in array" << endl;
	}

	// TEST 3  - size zero
	int testArray2[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray2Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told size is zero

	print(TestBit, testArray2);
	test->medianOfThree(testArray1, 0, 0, 5); // given size zero
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
		cout << "MOT: Passed TEST 3 of 6  - size zero" << endl;
	}

	// TEST 4  - first integer is not less than the second integer
	int testArray3[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray3Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told bad boundries

	print(TestBit, testArray3);
	test->medianOfThree(testArray1, 6, 5, 0);
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
		cout << "MOT: Passed TEST 4 of 6  - first integer is not less than the second integer" << endl;
	}

	// TEST 5  - out of bounds left
	int testArray4[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray4Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told bad boundries

	print(TestBit, testArray4);
	test->medianOfThree(testArray1, 6, -2, 3);
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
		cout << "MOT: Passed TEST 5 of 6  - out of bounds left" << endl;
	}

	// TEST 6  - out of bounds right
	int testArray5[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray5Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told bad boundries

	print(TestBit, testArray5);
	test->medianOfThree(testArray1, 6, 2, 7);
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
		cout << "MOT: Passed TEST 6 of 6  - out of bounds right" << endl;
	}

	return true; // if all tests passed return true
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

	// TEST 1 - Median of Three, even number of objects in array
	int testArray1[6] = { 4, 7, 2, 5, 0, 7 };

	print(TestBit, testArray1); // print out before test
	int TestInt0 = test->partition(testArray1, 6, 0, 5);  // sort using test's sort all 
	print(TestBit, testArray1); // print out after test
	int PartitionLocation1 = (0 + 5) / 2;
	for (int x = 0; x < PartitionLocation1; x++)  // check if expected result return false if not what expected
	{
		if (!(testArray1[x] <= testArray1[PartitionLocation1])) // all numbers located to the left of the partition should be less than or equal to it
		{
			return false;
		}
	}

	for (int x = ( ARRAY_SIZE(testArray1) -1); x > PartitionLocation1; x--)  // check if expected result return false if not what expected
	{
		if (!(testArray1[x] >= testArray1[PartitionLocation1])) // all numbers located to the right of the partition should be greater than or equal to it
		{
			return false;
		}
	}

	if (TestInt0 == -1) // should not return -1 if it does return false
	{
		return false;
	}
	if (TestBit)
	{
		cout << "partition: Passed TEST 1 of 6 - Median of Three, even number of objects in array" << endl;
	}

	// TEST 2 - Median of Three, odd number of objects in array
	int testArray[9] = { 4, 7, 0, 5, 2, 7, 47, 98, -13 };

	print(TestBit, testArray); // print out before test
	int TestInt01 = test->partition(testArray, 9, 0, 8);  // sort using test's sort all 
	print(TestBit, testArray); // print out after test
	int PartitionLocation2 = (0 + 8) / 2;
	for (int x = 0; x < PartitionLocation2; x++)  // check if expected result return false if not what expected
	{
		if (!(testArray[x] <= testArray[PartitionLocation2])) // all numbers located to the left of the partition should be less than or equal to it
		{
			return false;
		}
	}

	for (int x = ( ARRAY_SIZE(testArray) - 1); x > PartitionLocation2; x--)  // check if expected result return false if not what expected
	{
		if (!(testArray[x] >= testArray[PartitionLocation2])) // all numbers located to the right of the partition should be greater than or equal to it
		{
			return false;
		}
	}

	if (TestInt01 == -1) // should not return -1 if it does return false
	{
		return false;
	}
	if (TestBit)
	{
		cout << "partition: Passed TEST 2 of 6 - Median of Three, odd number of objects in array" << endl;
	}

	// TEST 3  - size zero
	int testArray2[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray2Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told size is zero

	print(TestBit, testArray2);
	int testInt2 = test->partition(testArray1, 0, 0, 5); // given size zero
	print(TestBit, testArray2);

	for (int x = 0; x < ARRAY_SIZE(testArray2); x++)  // check if expected result return false if not what expected
	{
		if (testArray2[x] != testArray2Result[x])
		{
			return false;
		}
	}

	if (testInt2 != -1) // should return -1 also if not return false
	{
		return false;
	}
	if (TestBit)
	{
		cout << "partition: Passed TEST 3 of 6  - size zero" << endl;
	}

	// TEST 4  - first integer is not less than the second integer
	int testArray3[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray3Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told bad boundries

	print(TestBit, testArray3);
	int testInt3 = test->partition(testArray1, 6, 5, 0);
	print(TestBit, testArray3);

	for (int x = 0; x < ARRAY_SIZE(testArray3); x++)  // check if expected result return false if not what expected
	{
		if (testArray3[x] != testArray3Result[x])
		{
			return false;
		}
	}

	if (testInt3 != -1) // should return -1 also if not return false
	{
		return false;
	}
	if (TestBit)
	{
		cout << "partition: Passed TEST 4 of 6  - first integer is not less than the second integer" << endl;
	}

	// TEST 5  - out of bounds left
	int testArray4[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray4Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told bad boundries

	print(TestBit, testArray4);
	int testInt4 = test->partition(testArray1, 6, -2, 3);
	print(TestBit, testArray4);

	for (int x = 0; x < ARRAY_SIZE(testArray4); x++)  // check if expected result return false if not what expected
	{
		if (testArray4[x] != testArray4Result[x])
		{
			return false;
		}
	}

	if (testInt4 != -1) // should return -1 also if not return false
	{
		return false;
	}
	if (TestBit)
	{
		cout << "partition: Passed TEST 5 of 6  - out of bounds left" << endl;
	}

	// TEST 6  - out of bounds right
	int testArray5[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray5Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told bad boundries

	print(TestBit, testArray5);
	int testInt5 = test->partition(testArray1, 6, 2, 7);
	print(TestBit, testArray5);

	for (int x = 0; x < ARRAY_SIZE(testArray5); x++)  // check if expected result return false if not what expected
	{
		if (testArray5[x] != testArray5Result[x])
		{
			return false;
		}
	}

	if (testInt5 != -1) // should return -1 also if not return false
	{
		return false;
	}
	if (TestBit)
	{
		cout << "partition: Passed TEST 6 of 6  - out of bounds right" << endl;
	}

	return true; // if all tests passed return true
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
	// TEST 1 - swap
	int testArray1[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray1Result[6] = { 4, 0, 2, 5, 7, 7 };

	print(TestBit, testArray1); // print out before test
	test->swap(testArray1, 6,1,4);  // sort using test's sort all 
	print(TestBit, testArray1); // print out after test

	if (testArray1[1] != testArray1Result[1])
	{
		return false;
	}
	if (testArray1[4] != testArray1Result[4])
	{
		return false;
	}
	if (TestBit)
	{
		cout << "swap Passed TEST 1 of 4 - swap" << endl;
	}


	// TEST 2  - size zero
	int testArray2[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray2Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told size is zero

	print(TestBit, testArray2);
	test->swap(testArray2, 0, 3, 5);
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
		cout << "swap Passed TEST 2 of 4 - size zero" << endl;
	}

	// TEST 3  - out of bounds left
	int testArray4[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray4Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told bad boundries

	print(TestBit, testArray4);
	test->swap(testArray1, 6, -3, 4);
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
		cout << "swap Passed TEST 3 of 4  - out of bounds left" << endl;
	}

	// TEST 4  - out of bounds right
	int testArray5[6] = { 4, 7, 2, 5, 0, 7 };
	int testArray5Result[6] = { 4, 7, 2, 5, 0, 7 }; // should remain the same if sortall is told bad boundries

	print(TestBit, testArray5);
	test->swap(testArray1, 6, 2, 7);
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
		cout << "swap Passed TEST 4 of 4  - out of bounds right" << endl;
	}


	return true; // if all tests passed return true

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
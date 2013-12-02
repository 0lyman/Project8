#pragma once
#include "QSTestInterface.h"
#include <array>
#include <string>
class QSTest :
	public QSTestInterface
{
public:
	QSTest();
	~QSTest();

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
	virtual bool testSortAll(QSInterface* test);

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
	virtual bool testSort(QSInterface* test);

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
	virtual bool testMedianOfThree(QSInterface* test);

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
	virtual bool testPartition(QSInterface* test);

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
	virtual bool testSwap(QSInterface* test);

	void print(bool TestBit, int array[]);
protected:
	bool TestBit;
};


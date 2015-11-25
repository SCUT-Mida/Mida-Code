//============================================================================
// Name        : QuickSort.cpp
// Author      : @SCUT-Mida
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Algorithm--QuickSort in C++, Time complexity:worstO(n^2);expectO(nlgn)
//============================================================================

#include <iostream>
using namespace std;

#include "..\..\Include\common.h"                      //The common struct for Algorithm

void swap(sortArray_t *sortArray,int index_i,int index_j)   //sortArray[index_i]<==>sortArray[index_j]
{
	SORT_TYPE temp;
	temp = sortArray->array[index_i];
	sortArray->array[index_i] = sortArray->array[index_j];
	sortArray->array[index_j] = temp;
}

int Partition(sortArray_t *sortArray,int low,int high)    //To split the site array
{
	SORT_TYPE pivotValue = sortArray->array[low];    //Select the fist element as the pivot
	while(low < high)
	{
		while((low < high)&&(sortArray->array[high] >= pivotValue))
			high--;
		swap(sortArray,low,high);

		while((low < high)&&(sortArray->array[low] <= pivotValue))
			low++;
		swap(sortArray,low,high);
	}
	return low;
}

void QuickSort(sortArray_t *sortArray,int low,int high)
{
	int pivot;
	if(low <high)
	{
		pivot = Partition(sortArray,low,high);
		QuickSort(sortArray,low,pivot-1);
		QuickSort(sortArray,pivot+1,high);
	}
}

int main()
{
	/*Initial the data*/
	SORT_TYPE OriginalData[9] = {50,10,90,30,70,40,80,60,20};
	sortArray_t sortArray;
	sortArray.array = new SORT_TYPE[10];
	sortArray.Length = 9;
	sortArray.array[0] = 0;
	for(int i = 0 ; i < sortArray.Length ; i++)
		sortArray.array[i+1] = OriginalData[i];
	/*Initial the data*/
	cout << "!!!The Original Data!!!" << endl;
	for(int i = 0 ; i < sortArray.Length ; i++)
		cout << OriginalData[i] << " ";
	cout <<endl;

	QuickSort(&sortArray,1,sortArray.Length);

	cout << "!!!The QuickSort Data!!!" << endl;
	for(int i = 0 ; i < sortArray.Length ; i++)
			cout << sortArray.array[i+1] << " ";
		cout <<endl;

	return 0;
}

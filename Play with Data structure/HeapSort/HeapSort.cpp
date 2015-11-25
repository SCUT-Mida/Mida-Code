//============================================================================
// Name        : HeapSort.cpp
// Author      : @SCUT-Mida
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Algorithm--HeapSort in C++, Time complexity:O(nLogn)
//============================================================================

#include <iostream>
using namespace std;

#define SORT_TYPE int

typedef struct __SORT_ARRAY
{
	SORT_TYPE *array;
	int Length;
}sortArray_t;

void swap(sortArray_t *sortArray,int index_i,int index_j)   //sortArray[index_i]<==>sortArray[index_j]
{
	SORT_TYPE temp;
	temp = sortArray->array[index_i];
	sortArray->array[index_i] = sortArray->array[index_j];
	sortArray->array[index_j] = temp;
}

void HeapAdjust(sortArray_t *sortArray,int sNode,int heapSize)
{
	SORT_TYPE temp = sortArray->array[sNode];    //Save the start Node
	for(int i = sNode * 2; i <= heapSize; i *= 2)
	{
		if((i < heapSize) && sortArray->array[i] < sortArray->array[i+1])	//If the LeftChild < RightChild.
			i++;															//The index is recorded as the RightChild.
		if(temp < sortArray->array[i])		//If the child is bigger.
		{
			sortArray->array[sNode] = sortArray->array[i];	//Set the sNode as the MaxHeapTop.
			sNode = i;
		}
		else
			break;      					//If the startNode is bigger,end the Loop.
	}
	sortArray->array[sNode] = temp;			//If sNode hasn't changed,the startNode is max;otherwise insert the temp to MaxChild.
}

void buildHeap(sortArray_t *sortArray)		//build the MaxHeap
{
	for(int i = sortArray->Length / 2; i > 0 ; i--)
		HeapAdjust(sortArray,i,sortArray->Length);
}

void HeapSort(sortArray_t *sortArray)
{
	buildHeap(sortArray);
	for(int i = sortArray->Length; i > 1 ; i--)
	{
		swap(sortArray,1,i);
		HeapAdjust(sortArray,1,i-1);
	}
}


int main()
{
	SORT_TYPE OriginalData[9] = {50,10,90,30,70,40,80,60,20};
	sortArray_t sortArray;
	sortArray.array = new SORT_TYPE[10];
	sortArray.Length = 9;
	sortArray.array[0] = 0;
	for(int i = 0 ; i < sortArray.Length ; i++)
		sortArray.array[i+1] = OriginalData[i];

	cout << "!!!The Original Data!!!" << endl;
	for(int i = 0 ; i < sortArray.Length ; i++)
		cout << OriginalData[i] << " ";
	cout <<endl;
	HeapSort(&sortArray);

	cout << "!!!The HeapSort Data!!!" << endl;
	for(int i = 0 ; i < sortArray.Length ; i++)
			cout << sortArray.array[i+1] << " ";
		cout <<endl;

	return 0;
}

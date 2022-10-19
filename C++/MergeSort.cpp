/*
Merge sort is a divide and conquer comparison-based sorting algorithm. It works as follows:-
1. Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).
2. Repeatedly merge sublists to produce new sublists until there is only 1 sublist remaining. This will be the sorted list.

-----Complexity - O(n·log n)-----
*/

#include <iostream>
using namespace std;


void mergeSort(int list[],int low,int mid,int high)
{
	int i, mi, k, lo, temp[50];
	lo = low;
	i = low;
	mi = mid + 1;
	while ((lo <= mid) && (mi <= high))
	{
		if (list[lo] <= list[mi])
		{
			temp[i] = list[lo];
			lo++;
		}
		else
		{
			temp[i] = list[mi];
			mi++;
		}
		i++;
	}
	if (lo > mid)
	{
		for (k = mi; k <= high; k++)
		{
			temp[i] = list[k];
			i++;
		}
	}
	else
	{
		for (k = lo; k <= mid; k++)
		{
			temp[i] = list[k];
			i++;
		}
	}
	for (k = low; k <= high; k++)
	{
		list[k] = temp[k];
	}
}

void partition(int list[],int low,int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high) / 2;
		partition(list, low, mid);
		partition(list, mid + 1, high);
		mergeSort(list, low, mid, high);
	}
}

int main()
{
	int i, size;

	cout<<"Enter total number of elements:";
	cin>>size;
	int arr[size];
	cout<<"Enter the elements:\n";
	for(i = 0; i < size; i++)
	{
		cin>>arr[i];
	}

	partition(arr, 0, size - 1);

	cout<<"After merge sort:\n";
	for(i = 0;i < size; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;

}


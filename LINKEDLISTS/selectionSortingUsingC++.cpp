//Selection Sort
/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.

*/
#include<iostream>
using namespace std;
void printArray(int a[],int n)
{ cout<<"\narray is \n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i]<<" ";
	}
}
void selectionSorting(int a[],int n)
{ int index,temp;
	for(int i=0;i<n-1;i++)
	{ int min=a[i];
	for(int j=i+1;j<n;j++)
	{
		if(a[j]<min)
		{ 
			min=a[j];
			index=j;
				
		}
	}
	if(a[i]>min)
	{
		temp=a[i];
	a[i]=a[index];
	a[index]=temp;
	}
	
	}
		printArray(a,n);
}
int main()
{
	int a[20],n;
	cout<<"enter no of ele in array\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nenter ele \n";
		cin>>a[i];
	}
	printArray(a,n);
	cout<<"\nafter sorting\n";
	selectionSorting(a,n);

}

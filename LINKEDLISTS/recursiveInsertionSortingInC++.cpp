//insertion sorting
/*
// Sort an arr[] of size n
insertionSort(arr, n) 
    Loop from i = 1 to n-1.
       a) Pick element arr[i] and insert
          it into sorted sequence arr[0..i-1] 
          
*/
#include<iostream>
using namespace std;
void printArray(int a[],int n)
{ cout<<"\nnew array is \n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void recursiveInsertionSorting(int a[],int n)
{
	if(n<=1) return;
	recursiveInsertionSorting(a,n-1);
	int last=n-1;
	int secondlast=n-2;
	while(secondlast>=0&&a[secondlast]>last)
	{
		a[secondlast+1]=a[secondlast];
		secondlast--;
	}
	a[secondlast+1]=last;
}
int main()
{
	int a[20],n;
	cout<<"enter no of ele to insert in array\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter ele to insert\n";
		cin>>a[i];
	}
	printArray(a,n);
	recursiveInsertionSorting(a,n);
	printArray(a,n);
}

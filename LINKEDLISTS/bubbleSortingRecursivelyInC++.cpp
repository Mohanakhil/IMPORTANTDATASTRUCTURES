//Recursive Bubble Sort
/*
First Pass: 
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1. 
( 1 5 4 2 8 ) –> ( 1 4 5 2 8 ), Swap since 5 > 4 
( 1 4 5 2 8 ) –> ( 1 4 2 5 8 ), Swap since 5 > 2 
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
Second Pass: 
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ) 
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.
Third Pass: 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 ) 
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
Following is iterative Bubble sort algorithm : 
*/
#include<iostream>
using namespace std;
void printArray(int a[],int n)
{ cout<<"\nnew array is \n";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
void bubbleSorting(int a[],int n)
{
	if(n==1) return;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			int temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}
	}
	return bubbleSorting(a,n-1);
}
int main()
{ int a[20],n;
cout<<"enter no of ele in array\n";
cin>>n;
for(int i=0;i<n;i++)
{
	cout<<"enter ele to insert\n";
	cin>>a[i];
}
printArray(a,n);
bubbleSorting(a,n);
printArray(a,n);
	
}

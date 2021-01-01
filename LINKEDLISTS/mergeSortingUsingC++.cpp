//Merge Sort
/*
 Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. See the following C implementation for details.

MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
The following diagram from wikipedia shows the complete merge sort process for an example array {38, 27, 43, 3, 9, 82, 10}. If we take a closer look at the diagram, we can see that the array is recursively divided in two halves till the size becomes 1. Once the size becomes 1, the merge processes come into action and start merging arrays back till the complete array is merged.
*/
#include<iostream>
using namespace std;
void printArray(int a[],int n)
{
	cout<<"\nnow array  is\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i]<<" ";
	}
}
void merge(int a[],int n,int left,int mid,int right)
{int b[20]={0};
	int i=left,j=mid+1,k=left;
	while(i<=mid&&j<=right)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			k++;i++;
		}
		else 
		{
			b[k]=a[j];
			k++;j++;
		}
	}
	if(i>mid)
	{ 
	while(j<=right)
	{
	b[k]=a[j];
	k++;j++;
	}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=a[i];
			k++;i++;
		}
	}
for(k=left;k<=right;k++)
{
	a[k]=b[k];
}
printArray(b,n);
}
void divide(int a[],int n,int left,int right)
{
	if(left<right)
	{	int mid=(left+right)/2;
		divide(a,n,left,mid);
		divide(a,n,mid+1,right);
		merge(a,n,left,mid,right);
	}
}
int main()
{
	int a[20],n;
	cout<<"enter no of ele in array\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter ele to insert\n";
		cin>>a[i];
	}
	printArray(a,n);
	divide(a,n,0,n-1);
}

//Merge Sort
/*
 Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
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
*/
#include<stdio.h>
void printArray(int a[],int n)
{ printf("\n new array is \n");

	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
void merge(int a[],int mid,int left,int right)
{
	int lefttemp=mid-left+1;
	int righttemp=right-mid;
	int LEFT[lefttemp],RIGHT[righttemp];
	for(int i=0;i<lefttemp;i++)
	{
		LEFT[i]=a[left+i];
	}
	for(int j=0;j<righttemp;j++)
	{
		RIGHT[j]=a[j+mid+1];
	}
	int i=0,j=0,k=left;
	while(i<lefttemp&&j<righttemp)
	{
		if(LEFT[i]<=RIGHT[j])
		{
			a[k]=LEFT[i];
			i++;
		}
		else
		{
			a[k]=RIGHT[j];
			j++;
		}
		k++;
	}
	while(i<lefttemp)
	{
		a[k]=LEFT[i];
		i++;
		k++;
	}
	while(j<righttemp)
	{
		a[k]=RIGHT[j];
		j++;
		k++;
	}
	
}
void mergeSorting(int a[],int n,int left,int right)
{

	if(left>=right) return;
		int mid=(left+(right-1)/2);
		mergeSorting(a,n,left,mid);
		mergeSorting(a,n,mid+1,right);
		merge(a,mid,left,right);
}
int main()
{
	int a[20],n;
	printf("enter no of ele in array\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{printf("enter ele to insert\n");
	scanf("%d",&a[i]);
	}
	printArray(a,n);
	mergeSorting(a,n,0,n-1);
	printArray(a,n);
}


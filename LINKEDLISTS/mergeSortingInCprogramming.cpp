//Merge Sort
/*
Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. See the following C implementation for details.

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
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
void merge(int a[],int left,int middle,int right)
{
int firsthalf=middle-left+1;
int secondhalf=right-middle;
int LEFT[firsthalf],RIGHT[secondhalf];
for(int i=0;i<firsthalf;i++)
{
LEFT[i]=a[left+i];
}
for(int j=0;j<secondhalf;j++)
{
	RIGHT[j]=a[middle+1+j];
}	

int i=0,j=0,k=left;
while(i<firsthalf&&j<secondhalf)
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
while(i<firsthalf)
{
	a[k]=LEFT[i];
	i++;
	k++;	
}
while(j<secondhalf)
{
	a[k]=RIGHT[j];
	j++;
	k++;
}

}
void mergeSort(int a[],int n,int left,int right)
{ 
	if(left>right)
	{
		int middle=(left+(right-1)/2);
		mergeSort(a,n,left,middle);
		mergeSort(a,n,middle+1,right);
		merge(a,left,middle,right);
	}
}
int main()
{ 
	int a[20],n;
	printf("\nenter no of ele in array\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nenter ele in array\n");
		scanf("%d",&a[i]);
	}
	printArray(a,n);
	mergeSort(a,n,a[0],n);
	printf("\nafter merge sorting\n");
	printArray(a,n);
}

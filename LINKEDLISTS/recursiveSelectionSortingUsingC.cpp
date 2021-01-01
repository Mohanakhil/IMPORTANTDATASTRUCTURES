//RECURSIVE SELECTION SORTING
#include<stdio.h>
void printArray(int a[],int n)
{ printf("\n array is\n");
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void recursiveSelectionSorting(int a[],int n)
{
	if(n==1) return;
	int secondlast=n-2;
	int last=n-1;
	recursiveSelectionSorting(a,n-1);
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
	printf("enter no of ele in array\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{ printf("\nenter ele\n");
		scanf("%d",&a[i]);
	}
	printArray(a,n);
	recursiveSelectionSorting(a,n);
	printArray(a,n);
	
}

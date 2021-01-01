#include<stdio.h>
void printArray(int a[],int n)
{ printf(" array is\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int mergeSort(int a[],int n,int left,int mid,int right,int b[])
{
	int i,j,k;
	i=left;
	j=mid+1;
	k=left;
	while(i<=mid&&j<=right)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
			k++;
			printf("\nhi entered while loop of if\n");
		}
		else 
		{
			b[k]=a[j];
		j++;
		k++;
			printf("\nhi entered while loop of else\n");
		}

	}
	if(i>mid)
	{ printf("\nhi entered i>mid cond\n");
		while(j<=right)
	{
		b[k]=a[j];
		k++;j++;
	}
	}
	else 
	{printf("\nhi entered i<mid cond\n");
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	return b[0];

	
}
void divide(int a[],int n,int left,int right,int b[])
{
	if(left<right)
	{

	int mid=(left+right)/2;
	divide(a,n,left,mid,b);
	divide(a,n,mid+1,right,b);
	b[0]= mergeSort(a,n,left,mid,right,b);

	}
}
int main()
{
	int a[20],n,b[20];
	printf("enter no of ele in array\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter ele to insert\n");
		scanf("%d",&a[i]);
	}
	printArray(a,n);
	divide(a,n,0,n-1,b);
	printArray(b,n);
}

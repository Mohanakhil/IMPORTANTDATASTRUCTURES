//merge sorting
#include<stdio.h>
void printArray(int a[],int n)
{ printf("\nNOW array is\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int merge(int a[],int n,int left,int mid,int right)
{ int b[20]={0};
	int i=left,j=mid+1,k=left;
while(i<=mid&&j<=right)
{
	if(a[i]<=a[j])
	{
		b[k]=a[i];
		k++;
		i++;
	}
	else
	{
		b[k]=a[j];
		j++;
		k++;
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

}
void divide(int a[],int n,int left,int right)
{ 
	if(left<right)
	{
		int mid=(left+right)/2;
		
		printf("\nleft= %d\n",left);
		printf("\nmid= %d\n",mid);
		printf("\nright= %d\n",right);
		divide(a,n,left,mid);
		divide(a,n,mid+1,right);
	merge(a,n,left,mid,right);
	}
}
int main()
{
	int a[20],n;
	printf("enter number of ele in arrray\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("enter ele\n");
		scanf("%d",&a[i]);
	}
		printArray(a,n);
		divide(a,n,0,n-1);
		printArray(a,n);
		
}

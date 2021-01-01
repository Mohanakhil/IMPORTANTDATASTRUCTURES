//merge sorting
#include<iostream>
using namespace std;
void printArray(int a[],int n)
{ cout<<"array is \n";
	for(int i=0;i<n;i++)
	{cout<<a[i]<<" ";
	}
}
void merge(int a[],int n,int left,int mid,int right)
{ int b[20]={0};
	int i=left,j=mid+1,k=left;
	while(i<=mid&&j<=right)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;k++;
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
	for(int k=left;k<=right;k++)
	{
		a[k]=b[k];
	}
}
void divide(int a[],int n,int left,int right)
{ if(left<right)
{
int mid=(left+right)/2;
divide(a,n,left,mid);
divide(a,n,mid+1,right);
merge(a,n,left,mid,right);
}
	
}
int main()
{
	int a[20],n;
	cout<<"enter no of ele in  array\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cout<<"enter ele \n";
	cin>>a[i];
	}
	printArray(a,n);
	divide(a,n,0,n-1);
		printArray(a,n);
}

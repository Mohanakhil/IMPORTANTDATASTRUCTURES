//Exponential Search
/*
How to find the range where element may be present? 
The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until last element of a subarray is not greater. 
Once we find an index i (after repeated doubling of i), we know that the element must be present between i/2 and i (Why i/2? because we could not find a greater value in previous iteration)
*/
#include<iostream>
#include<math.h>
using namespace std;
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void exponentialSearch(int a[],int n)
{
int i=0,step=1,x;
cout<<"enter ele to search for in array\n";
cin>>x;
while(i<=n)
{ if(a[i]==x)
{	cout<<" ele "<<x<<" is present at index= "<<i<<"\n";
	return ;
}
else if(x>a[i])
{		if(step<sqrt(n)-1)
			step=step+1;
	i=i+step;	
	cout<<" i value is "<<i<<"\n";
}
else if(x<a[i])
{
	int left=i-step;
	int right=i;
	while(left<=right)
	{ cout<<" left = "<<left<<" right= "<<right<<"\n";
		if(x==a[left])
		{
			cout<<"ele "<<x<<" is found at index= "<<left<<"\n";
			return;
		}
		left++;
	}
	
}
}
cout<<" ele"<<x<<" is not found\n";
}
int main()
{
	int a[10],n,choice;
	cout<<"enter no of ele in array\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter ele to insert\n";
		cin>>a[i];
	}
	do
	{
	printArray(a,n);
	exponentialSearch(a,n);
	cout<<"enter 0 for termination\n";
	cin>>choice;
	}while(choice!=0);
}

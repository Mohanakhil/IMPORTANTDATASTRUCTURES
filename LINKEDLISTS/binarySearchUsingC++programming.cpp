//Given a sorted array arr[] of n elements, write a function to search a given element x in arr[]
//Binary Search
//O(logn)
#include<iostream>
using namespace std;
void printList(int a[],int n)
{
	for(int i=0;i<n;i++)
	{cout<<" "<<a[i]<<" ";
	}
}
void binarySearch(int a[],int n)
{
	int left=0,right=n-1,x;
	cout<<"enter ele to search\n";
	cin>>x;
	while(left<=right)
	{
		int mid=(left+(right-1)/2);
		cout<<"mid is "<<a[mid]<<"\n";
		if(x==a[mid]) 
	{
			cout<<"ele "<<x<<" found at index = "<<mid;
			return;
	}
		if(x>a[mid])
		{
			left=mid+1;
			
		}
		if(x<a[mid])
		{
			right=mid-1;
		}
	
	}
		cout<<"ele "<<x<<"is not found";
}
int main()
{
	int a[10],n;
	cout<<"enter no of ele in array\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter ele in array\n";
		cin>>a[i];
	}
	printList(a,n);
	binarySearch(a,n);
}

//Linear Search
//O(n)
//Given an array arr[] of n elements, write a function to search a given element x in arr[].
#include<iostream>
using namespace std;
void linearSearch(int a[],int n)
{int x; 
cout<<"enter ele to search for\n";
cin>>x;
	for(int i=0;i<n;i++)
	{
		if(a[i]==x) 
		{
		cout<<"\nele "<<a[i]<<" is found at index= "<<i;
		return ;
		}
	}
	 cout<<"ele is not found\n";
	
}
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<" "<<a[i]<<" ";
}
int main()
{
	int a[10],n;
	cout<<"ente no of ele in array\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter ele to insert in array\n";
		cin>>a[i];
		
	}
	printArray(a,n);
	linearSearch(a,n);
}

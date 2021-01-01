//BINARY SEARCH  USING RECURSION
#include<iostream>
using namespace std;
void printList(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<" "<<a[i];
}
void binarySearch(int a[],int n,int left,int right,int x)
{ 

int mid=(left+(right-1)/2);
if(x==a[mid]) cout<<"\nele "<<x<<" is present at index= "<<mid;
else if(x>a[mid]) return binarySearch(a,n,mid+1,right,x);
else if(x<a[mid]) return binarySearch(a,n,left,mid-1,x);
}
int main()
{
	int a[10],n;
	cout<<"enter no of ele in array\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cout<<"enter ele\n";
	cin>>a[i];
	}
	printList(a,n);
	int left=0,right=n-1,x=0;
	cout<<"\nenter ele to search\n";
	cin>>x;
	binarySearch(a,n,left,right,x);
}

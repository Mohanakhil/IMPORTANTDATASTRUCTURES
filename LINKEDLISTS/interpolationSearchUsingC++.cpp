//Interpolation Search
/*
// The idea of formula is to return higher value of pos
// when element to be searched is closer to arr[hi]. And
// smaller value when closer to arr[lo]
pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]

arr[] ==> Array where elements need to be searched
x     ==> Element to be searched
lo    ==> Starting index in arr[]
hi    ==> Ending index in arr[]
o(log2(logn))
*/
#include<iostream>
using namespace std;
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i]<<" ";
	}
}
void interpolationSearch(int a[],int n)
{
	int x;
	cout<<"enter ele to search\n";
	cin>>x;
	int pos=0,left=0,right=n-1;

	while(pos<=n)
	{  	pos= left+(x-a[left])*(right-left)/(a[right]-a[left]);
		if(x==a[pos]) 
		{
			cout<<"ele "<<x<<"is present at index= "<<pos<<"\n";
			return;
			
		}
		else if(x>a[pos])
		{
			left=pos+1;
			
		}
		else if(x<a[pos])
		{
			right=pos-1;
		}
	}
	cout<<" ele "<<x<<" is not found\n";
}
int main()
{ int choice;
	int a[10],n;
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
	interpolationSearch(a,n);
	cout<<"\npress 0 for termination\n";
	cin>>choice;
	}while(choice!=0);
	
}

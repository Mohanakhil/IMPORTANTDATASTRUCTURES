//Jump Search
//o(sqrtn)
#include<iostream>
#include<math.h>
using namespace std;
void printArray(int a[],int n)
{ cout<<"new array is\n";
	for(int i=0;i<n;i++)
	cout<<" "<<a[i]<<" ";
}
void jumpSearch(int a[],int n)
{ int step=sqrt(n),i=0,x;

	cout<<"\nenter ele to search\n";
	cin>>x;
	while(i<=n)
	{ 
	if(x>a[i])
	{
		i=i+step;
	}
	else if(x<=a[i])
	{int j=0;
	while(j<=i)
	{ if(a[j]==x) 
	{
	cout<<"ele "<<x<<" is found at index= "<<j;
	return ;
	}
		j++;
	}
	}	
	}
}
int main()
{	int choice=0;
	int a[10],n;
	cout<<"\nenter no of ele in array\n";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"\nenter ele to insert\n";
		cin>>a[i];
		
	}
		do
	{
	printArray(a,n);
	jumpSearch(a,n);

	cout<<"\nenter 0 for termination\n";
	cin>>choice;
	}while(choice!=0);
}

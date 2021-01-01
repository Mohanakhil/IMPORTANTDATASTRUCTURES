//Fibonacci Search
/*
Fibonacci Numbers are recursively defined as F(n) = F(n-1) + F(n-2), F(0) = 0, F(1) = 1. 
First few Fibinacci Numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …

*/
#include<stdio.h>
#include<math.h>
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}
void fibonacciSearch(int a[],int n)
{ int x;
printf("\nenter ele to search for in array\n");
scanf("%d",&x);
	int left,right;
	int prev=0,position=1;
	while(position<n)
	{
		if(a[position]==x) 
		{
			printf("ele %d is present at index= %d\n",x,position);
		return ;	
		}
		else if(x>a[position])
		{   if(position<sqrt(n))
		{
		 	prev=position;
			position=position+prev;
		}
		else
		position=position+prev;
			printf("\nprev= %d  and pos=%d\n",prev,position);
			
		}
		else if(x<a[position])
		{
			while(prev<=position)
			{
				if(a[prev]==x) 
				{
					printf("ele %d is present at index= %d\n",x,prev);
					return ;
				}
				prev++;
			}
		}
	}
}
int main()
{ int a[10],n;
printf("enter no of ele in array\n");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
	printf("enter ele to enter\n");
	scanf("%d",&a[i]);
	
}
int choice;
do
{
printArray(a,n);
fibonacciSearch(a,n);
printf("press 0 for termination\n");
scanf("%d",&choice);
}while(choice!=0);
}

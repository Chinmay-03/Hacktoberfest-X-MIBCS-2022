void swap(int* x,int* y)
    {
        int temp=*x;
        *x=*y;
        *y=temp;
    }    
int shouldPunish (int roll[])
    {
       
       int count=0,sum=0;
       for(int i=0;i<n-1;i++)
       {
           for(int j=0;j<n-i-1;j++)
           {
               if(roll[j]>roll[j+1])
               {
                   swap(&roll[j], &roll[j+1]);
                   count++;
               }
           }
       }
        return 0;
    }


#include<iostream>
using namespace std;

int main()
{
	int n;
	printf("Enter the length of array:");
	scanf("%d",&n);
	int a[1000];
	for (int i = 0; i < n; i++)
	{   printf("Enter the number:");
		scanf("%d",&a[i]);
	}
	printf("Before sorting: ");
	for(int i=0;i<n;i++)
    {
        printf("%d,",a[i]);
    }
	
	printf("\n");
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                   
            }
        }
    }
    printf("After sorting: ");
    for(int i=0;i<n;i++)
    {
        printf("%d,",a[i]);
    }
	

	return 0;
		

	
}

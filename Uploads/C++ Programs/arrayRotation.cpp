#include<bits/stdc++.h>
using namespace std;

void Rotate(int arr[],int n,int d)
{
	int temp[n];
	int k=0;
	
	for (int i=d;i<n;i++)
	{
		temp[k]=arr[i];
		k++;
	}
	
	for (int i=0;i<d;i++)
	{
		temp[k]=arr[i];
		k++;
	}
	
	for (int i=0;i<n;i++)
	{
		arr[i]=temp[i];
		
	}
}

void PrintTheArray(int arr[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
}

int main()
{	
	int i;
	int arr[]={1,2,3,4,5,6,7};
	int N=sizeof(arr)/sizeof(arr[i]);
	int d=2;
	
	Rotate(arr,N,d);
	PrintTheArray(arr,N);
	return 0;
}

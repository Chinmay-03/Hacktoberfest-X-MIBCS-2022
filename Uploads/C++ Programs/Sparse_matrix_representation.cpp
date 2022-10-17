#include <iostream>

using namespace std;

int main()
{

int m[10][10],nr,nc,sp[50][3],i,j,k;

cout<<"Enter number of rows and columns:";
cin>>nr>>nc;
cout<<"\nEnter the matrix:";

for(i=0;i<nr;i++)
for(j=0;j<nc;j++)
cin>>m[i][j];

k=1;
for(i=0;i<nr;i++)
for(j=0;j<nr;j++)
if(m[i][j] != 0)
{
	sp[k][0]=i;
	sp[k][1]=j;
	sp[k][2]=m[i][j];
	k++;
}
	sp[0][0]=nr;
	sp[0][1]=nc;
	sp[0][2]=k-1;
	
	cout<<"\nSparse matrix is:\n";
	cout<<"Rows\tColumns\tvalues"<<endl;
	for(i=0;i<=sp[0][2];i++) 
    {
	for(j=0;j<3;j++)
	cout<<sp[i][j]<<"\t";
	cout<<endl;
	}

    return 0;
}

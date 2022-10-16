#include <iostream>
#include <math.h>
using namespace std;


struct poly
{
	int coeff;
	int expo;
};

struct add
{
	int coeff;
	int expo;
};



int get_poly(struct poly p[]);
void display_poly(struct poly p[],int terms);
int add_poly(struct poly p[],struct poly p2[],int terms,int terms2,struct add a[]);
void multi_poly(struct poly p[],struct poly p2[],int terms,int terms2);
void eval_poly(struct poly p[],int terms);
void seePoly(struct add a[],int terms);


int get_poly(struct poly p[])
{
	int t;
	cout<<"Enter the number of terms in polynomial :";
	cin>>t;
	for (int i=0;i<t;i++)
	{
		cout<<"Enter the "<<i+1<<"th Coefficient :";
		cin>>p[i].coeff;
		cout<<"Enter the "<<i+1<<"th Exponent :";
		cin>>p[i].expo;
	}
	return t;
}

void display_poly(struct poly p[],int terms)
{
	int k;
	for(k=0;k<terms-1;k++)
	{
		cout<<p[k].coeff<<"(x^"<<p[k].expo<<")+";
	}
	cout<<p[k].coeff<<"(x^"<<p[k].expo<<")";
}


int add_poly(struct poly p1[],struct poly p2[],int terms,int terms2,struct add a[])
{
	int i=0,j=0,k=0;
	
	while(i<terms && j<terms2)
	{
		if(p1[i].expo==p2[j].expo)
		{
			a[k].coeff=p1[i].coeff + p2[j].coeff;
			a[k].expo=p1[i].expo;

			i++;
			j++;
			k++;
		}
		else if(p1[i].expo>p2[j].expo)
		{
			a[k].coeff=p1[i].coeff;
			a[k].expo=p1[i].expo;
			i++;
			k++;
		}
		else
		{
			a[k].coeff=p2[j].coeff;
			a[k].expo=p2[j].expo;
			j++;
			k++;
		}
	}

	
	while(i<terms)
	{
		a[k].coeff=p1[i].coeff;
		a[k].expo=p1[i].expo;
		i++;
		k++;
	}
	
	while(j<terms2)
	{
		a[k].coeff=p2[j].coeff;
		a[k].expo=p2[j].expo;
		j++;
		k++;
	}

	return(k); 
}
 
void seePoly(struct add a[],int terms)
{
	int k;

	for(k=0;k<terms-1;k++)
	{
		cout<<a[k].coeff<<"(x^"<<a[k].expo<<")+";
	}
	cout<<a[k].coeff<<"(x^"<<a[k].expo<<")";
}



void multi_poly(struct poly p[],struct poly p2[],int terms,int terms2)
{
	int i,j;
	for (i=0;i<terms;i++)
	{
		for (j=0;j<terms2;j++)
		{
			cout<<(p[i].coeff)*(p2[j].coeff)<<"(x^"<<p[i].expo+p2[j].expo<<" )+";
		}
	}
}


void eval_poly(struct poly p[],int terms)
{
	int i,x,sum=0;
	cout<<"\nEnter the value of x :";
	cin>>x;
	for (i=0;i<terms;i++)
	{
		sum+=(p[i].coeff)*(pow(x,p[i].expo));
	}
	cout<<sum;
}
	
int main()
{
	int n,m,ch,value;
	int addCount;
	struct poly p[20];		//User Input
	struct poly p2[20];
	struct add a[30];

	do 
	{
		cout<<"-----------------------------------------------------------------------------------"<<endl;
		cout<<"\n\tMENU"<<endl;
		cout<<"\nEnter 1 for Addition of Polynomial\nEnter 2 for Multiplication of Polynomial\n";
		cout<<"Enter 3 for Evaluation of Polynomial\nEnter 4 for Exit"<<endl;
		cout<<"\nEnter your Choice :";
		cin>>ch;
		
		
		//Switchcase
		switch(ch)
		{
			case 1:	n=get_poly(p);
					m=get_poly(p2);
					cout<<"\n--------------------------------------------------------------------------"<<endl;
					cout<<"ADDITION OF THE POLYNOMIAL GIVES :"<<endl;
					addCount=add_poly(p,p2,n,m,a);
					seePoly(a,addCount);
					break;
					
			case 2: n=get_poly(p);
					m=get_poly(p2);	
					cout<<"\n--------------------------------------------------------------------------"<<endl;
					cout<<"MULTIPLICATION OF THE POLYNOMIAL GIVES :"<<endl;	
					multi_poly(p,p2,n,m);
					break;
					
			case 3:	n=get_poly(p);
					display_poly(p,n);
					cout<<"\n--------------------------------------------------------------------------"<<endl;
					cout<<"EVALUATION OF THE POLYNOMIAL GIVES :"<<endl;	
					eval_poly(p,n);
					break;
					
			case 4: cout<<"Exiting the Program"<<endl;
					break;
		}
	}while(ch>=1 && ch<=4);
	return 0;
}




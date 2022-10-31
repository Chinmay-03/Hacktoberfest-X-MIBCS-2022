#include<iostream>
using namespace std;

class complex
{
	int a,b;
	
	public:
		void input()
		{
			cout<<"\nPlease enter value of real part of complex number :";
			cin>>a;
			cout<<"\nPlease enter imaginary part of complex number :";
			cin>>b;
		}
		
		complex addition(complex obj)
		{
			complex temp;
			temp.a=a+obj.a;
			temp.b=b+obj.b;
			return temp;
		}
		
		void show()
		{
			cout<<"\nThe complex number is"<<a<<"+"<<b<<"i";
		}
};

main()
{
	complex j,k,r;
	cout<<"\nEnter a First Complex Number";
	
	j.input();
	cout<<"\nEnter a Second Complex Number";
	
	k.input();
	cout<<"\nComplex Number 1";
	
	j.show();
	cout<<"\nComplex Number 2";
	
	k.show();
	
	r=j.addition(k);
	cout<<"\nAddition Complex Number";
	
	r.show();
	
}

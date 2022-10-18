//multiple & default class template demonstration
#include<iostream>
using namespace std;
template <class T=char,class T1=int>
class hello
{
	public:
	T a;
	T1 b;
	hello(T x,T1 y)
	{
		a=x;
		b=y;
	}
	void display();
	
	
};
template <class T,class T1> //definition outside class template
void hello<T,T1>:: display()
	{
		cout<<"a = "<<a<<"\t b ="<<b<<endl;
	}

int main(void)
{
	hello<> ob(99,1.1);
	hello <float> obj(4.9,'A'); //default 2nd template argument is int 
    hello <float,char> obj1(4.9,'A');
	hello <int,float> obj2(9,11.7);
	ob.display();
	obj.display();
	obj1.display();
    obj2.display();
    //	cout<<obj.a<<endl;
    //cout<<obj1.a<<endl;

return 0;
}


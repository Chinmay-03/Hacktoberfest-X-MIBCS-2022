//function template and also overloading function template 

#include<iostream>
using namespace std;
template <class T>
void print(T a)
{
	cout<<a<<" I am templatisesd function :-) "<<endl;
}
void print(int a)
{
	cout<<a<<" I am not templatised function"<<endl;
}

int main(void)
{
print<int>(4);
print(4);	     //exact match take the higher priority
print<char>(65);
print<float>(4.99);


return 0;
}


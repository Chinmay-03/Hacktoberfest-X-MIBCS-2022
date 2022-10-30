#include<iostream>
using namespace std;
int main()
{
  / int num1,num2;

    //C++ Arithmetic operations

    cout<<"Enter first number:";
    cin>>num1;

    cout<<"Enter second number:";
    cin>>num2;

    cout<<num1+num2<<endl;
    cout<<num1-num2<<endl;
    cout<<num1*num2<<endl;
    cout<<num1/num2<<endl;
    cout<<num1%num2<<endl;

    /*C++ Logical Operations
    &&=Logiacl And
    ||=Logical Or
    !=Logical Not*/

    bool exp1=true,exp2=false;

    cout<<(exp1&&exp2)<<endl;
    cout<<(exp1||exp2)<<endl;
    cout<<(!exp1)<<endl;


     /*C++ Relational operations
        (==,!=,>.<,>=,<=)*/

    int num1,num2;

    cout<<"Enter first number:";
    cin>>num1;

    cout<<"Enter second number:";
    cin>>num2;

    
    cout<<(num1==num2)<<endl;
    cout<<(num1!=num2)<<endl;
    cout<<(num1>num2)<<endl;
    cout<<(num1<num2)<<endl;
    cout<<(num1<=num2)<<endl;
    cout<<(num1>=num2)<<endl;


    /*C++ Assignment operations
    (+=--> a+=1=> a=a+1
     -=--> a-=1=> a=a-1
     /=--> a/=1=> a=a/1
     %=--> a%=1=> a=a%1
    )*/

    num1+=3;
    num2+=2;
    cout<<num1<<endl;
    cout<<num2<<endl;

    num1-=2;
    num2-=3;
    cout<<num1<<endl;
    cout<<num2<<endl;


    return 0;
}

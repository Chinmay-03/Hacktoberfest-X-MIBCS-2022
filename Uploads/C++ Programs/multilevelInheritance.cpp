#include<iostream>
using namespace std;
class student
{
    protected:
    int rno;
    public:
    void get_no(int a)
    {
        rno=a;
    }
    void put_no(void)
    {
        cout<<"Roll No: "<<rno<<"\n";
    }
};

class test: public student          //first level derivation
{
    protected:
    float sub1, sub2;
    public:
    void get_marks(float,float);
    void put_marks(void);
};

void test::get_marks(float x,float y)
{
    sub1=x;
    sub2=y;
}
void test::put_marks()
{
    cout<<"Marks in subject 1: "<<sub1<<"\n";
    cout<<"Marks in subject 2: "<<sub2<<"\n";
}

class  result: public test      //Second level derivation
{
    float total;
    public:
    void display(void);
};

void result::display()
{
    total=sub1+sub2;
    put_no();
    put_marks();
    cout<<"Total: "<<total<<"\n";
}
int main()
{
    result s1;      //s1 created
    s1.get_no(11);
    s1.get_marks(85.0,99.5);
    s1.display();
    return 0;
}
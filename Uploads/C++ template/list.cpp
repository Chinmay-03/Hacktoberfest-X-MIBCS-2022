#include<iostream>
#include<list>
using namespace std;
void display(list<int> &l)
{
	list<int>::iterator iter;
	for(iter=l.begin();iter!=l.end();iter++)
	{
		cout<<*iter<<" ";
	}
	
}

int main(void)
{
	list<int> l;//list of 0 length
	
	l.push_back(100);
	l.push_back(20);
    //list<int>::iterator iter;
    //iter=l.begin();
    // cout<<*iter<<endl;        use display instead of this
    //cout<<*(++iter)<<endl;
    cout<<"\n list 1 is : ";
    display(l);
    
    list<int> l1(5);//zero list 0f 5 length
    list<int>::iterator iter1;
    iter1=l1.begin(); //begin() for pointing from start & rbegin() point from end
    *iter1=50;
    iter1++;
    *iter1=10;
    iter1++;
    *iter1=30;
    iter1++;
    *iter1=90;
    iter1++;
    *iter1=40;

   cout<<"\n list 2 is : " ;
   display(l1);
   
   
   
   l.sort();
   l1.sort();
   cout<<"\n list 1 after sorting : ";
   display(l);
   cout<<"\n list 2 after sorting : ";
   display(l1);
   l.merge(l1);//list 2 add into the 1st one
   cout<<"\n after merging : ";
   display(l);
   
   l.pop_back();
   l.remove(20);
   l.pop_front(); //for deleting particular element randomly
   cout<<"\n list after deleting : ";
   display(l);
   cout<<"\n final size of list 1 : "<<l.size(); 
   cout<<"\n final size of list 2 : "<<l1.size();  
return 0;
}


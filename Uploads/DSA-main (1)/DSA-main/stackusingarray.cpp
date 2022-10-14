#include <iostream>
using namespace std;
class stackusingarray{
    int *data;        // Dynamic allocation because we dont know the size of stack or array
    int nextIndex;    // Point to the top element
    int capacity;

    public:
     stackusingarray(int totalsize)   // this constructor used for the initialization of stack
     {
         data=new int[totalsize];     // we pass the totalszie of array and it is created
         nextIndex=0;                 // nextindex pointing to the zeroth index of the stack
         capacity=totalsize;          // capacity is equal to the totalsize
     }

     // Now we will write the function which will return the size the size of stack

     int size()
     {
         return nextIndex;
     }

     // Now we will check the stack weather it is empty or not

      bool isEmpty()
      {
          return nextIndex==0;
      }

      // Now using the function called push we will insert the value in stack

      void push(int ele)
      {
          if(nextIndex==capacity)    // if nextIndex is equal to capacity then no push take place
             cout<<"Stack is full";
          else 
            {
                data[nextIndex]=ele;    // if proper space is avilable then push the value at indexIndex positon
                nextIndex++;         // after pushing the value in stack then increment the value of nextIndex
            }       
      }

    //delete element in stack
    
    int pop()
    {
        if(isEmpty())
          { cout<<"Stack is empty";
           return 0;
          }
          nextIndex--;        // reduce the value of nextIndex i.e it will remove the top element
          return data[nextIndex];   // return the data of reduced size;
    }

    // acces the top element of stack

    int top()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty:";
            return 0;
        }
        return data[nextIndex-1];
    }  



};
int main() {

    stackusingarray s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"Top element: "<<s.top()<<endl;
    cout<<"Size of stack: "<<s.size()<<endl;
    cout<<"pop element: "<<s.pop()<<endl;
    cout<<"Size of stack: "<<s.size()<<endl;
    cout<<"Is empty or not: "<<s.isEmpty()<<endl;

   
}

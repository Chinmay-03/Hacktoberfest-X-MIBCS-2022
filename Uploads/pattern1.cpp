#include<iostream>
using namespace std;
int main()
{  
   

    int row = 1;
    while(row <= 5) {

        int col = 1;
        int value=row;
        while(col <= row) {
            cout<< value;
            value = value + 1;
            col=col+1;

        }
        cout<<endl;
        row = row + 1;
    }
    return 0;
}

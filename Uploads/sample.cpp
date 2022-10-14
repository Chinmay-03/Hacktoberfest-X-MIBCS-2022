#include <iostream>

using namespace std;

int main(){
int a, b, c;
  cout << "enter no" << endl;
  cin >> a;
  cout << "enter no" << endl;
  cin >> b;
  cout << "enter no" << endl;
  cin >> c;

  if (a > b) {
    if (a > c) {
      cout << "a is greater than c" << endl;
    } else {
      cout << "c is greater than a" << endl;
    }
  } else  {
    cout << "b is greater than a" << endl;
  }
  
  return 0;
  }

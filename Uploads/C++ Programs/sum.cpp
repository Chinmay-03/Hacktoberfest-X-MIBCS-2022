#include<iostream>
#include<vector>
using namespace std;

int Sum (vector<int>a) {
  int sum = 0;
  for(int i:a)
    sum +=i;
 return sum;
}

int main() {
  
  vector <int> arr = {1,2,3,4};
  cout<<Sum(arr;
  return 0;
}

//program for rain water tapping problem

#include<iostream>
using namespace std;

int max(int a, int b) {
    if(a>b){
        return a;
    } else {
        return b;
    }
}

int min(int a, int b) {
    if(a<b){
        return a;
    } else {
        return b;
    }
}
 
int trap(int* hgt, int hgtsize){

    int* l=(int*)malloc(sizeof(int)*hgtsize);
    int* r=(int*)malloc(sizeof(int)*hgtsize);
    
    l[0]=hgt[0];
    for(int i=1; i<hgtsize; i++)
    {
        l[i]=max(l[i-1],hgt[i]);
    }
    
    r[hgtsize-1]=hgt[hgtsize-1];
    for(int i=hgtsize-2; i>=0; i--)
    {
        r[i]=max(r[i+1],hgt[i]);
    }
    int val,sum=0;
    for(int i=1; i<hgtsize-1; i++)
    {
        val=min(l[i],r[i]);
        if(val>hgt[i])
        {
            sum+=val-hgt[i];
        }
    }
    return sum;
     
}

int main() {
  int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout<<( trap(arr, n) )<<endl;
  return 0;
}

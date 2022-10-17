#include<bits/stdc++.h>
using namespace std;

void countSort(int a[],int n){
    int k=a[0];
    for(int i=1;i<n;i++) k=max(k,a[i]);
    int count[10]={0};
    for(int i=0;i<n;i++) count[a[i]]++;
    int j=0;
    for(int i=0;i<=k;i++)
        while(count[i]--){
            a[j]=i;
            j++;
        }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    countSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
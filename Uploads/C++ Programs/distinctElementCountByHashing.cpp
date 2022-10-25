#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main() {

    int arr[] = {15,12,13,12,13,13,18};
    int n = sizeof(arr)/sizeof(arr[0]);
    unordered_set<int> s;
    for (int i=0;i<n;i++) {
        s.insert(arr[i]);
    }
    cout<<( s.size() )<<endl;

    return 0;
}

/*
    BETTER SYNTAX WISE FOR SOLVING THIS QUESTION 

unordered_set<int> s(arr, arr+n);

*/

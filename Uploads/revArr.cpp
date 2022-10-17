# include <iostream>
# include <vector>
using namespace std;

void printArr (vector<int> arr, int n) {
    cout << "Printing the vector\t";
    for (int i=0; i<n; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

void reverse( vector<int> &arr, int n, int pos) {

    cout << "Reversing the vector..." << endl;

    int start = pos + 1;
    int end = n-1;

    while ( start < end ) {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}


int main () {

    vector<int> arr = {10, 4, 5, 2, 3, 6, 1, 3, 6};

    printArr(arr,arr.size());
    reverse(arr,arr.size(),3);
    printArr(arr,arr.size());
    return 0;
}
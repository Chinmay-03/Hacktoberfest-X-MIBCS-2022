// pivot in arr

# include <iostream>
# include <vector>
using namespace std;

int pivot ( vector<int>& arr) {

    int sum = 0;

    for (int i:arr)
        sum +=i;

    int LSum = 0, RSum = sum;

    int i = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        RSum -= arr[i];

        if ( LSum == RSum)
            return i;
        LSum += arr[i];
    }
    

    return -1;
}
int main () {

    vector <int> arr = {1,7,3,6,5,6};
    cout<<pivot(arr);
}

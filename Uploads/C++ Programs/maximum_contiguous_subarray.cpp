// C++ program to print largest contiguous array sum
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<Int> v)
{
  int size = v.size();
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

int main()
{
  int n ;cin>>n;
  vector<int> v;
  for(int i=0; i< n; i++){
    int num ;cin>>num;
    v.push_back(num);
  }
	// Function Call
	int max_sum = maxSubArraySum(v);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}

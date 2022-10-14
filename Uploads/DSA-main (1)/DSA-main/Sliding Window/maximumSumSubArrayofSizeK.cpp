// Geeksforgeeks Practice question 
// Link : https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1


int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        
        int i=0,j=0,mx=INT_MIN,sum=0;
        while(j<N)
        {
            sum=sum+Arr[j];
            if(j-i+1 < K)
            {
                j++;
            }
            else if(j-i+1==K)
            {
                mx=max(mx,sum);
                sum=sum-Arr[i];
                i++;
                j++;
            }
        }
        
        return mx;
    }

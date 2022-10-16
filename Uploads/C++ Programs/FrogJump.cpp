#include<bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    int prev=0,prev1=0;
    int ans;
    for(int i=1;i<n;i++)
    {
        int fs=prev1+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)
        {
            ss=prev+abs(heights[i]-heights[i-2]);
        }
        ans=min(fs,ss);
        prev=prev1;
        prev1=ans;
        
        
    }
    
    return prev1;
}

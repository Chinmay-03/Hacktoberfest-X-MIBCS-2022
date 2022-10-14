// Codestudio:


vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{   vector<int> v;
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(int i=0;i<n;i++)
    {
        maxheap.push(arr[i]);
        minheap.push(arr[i]);
        
        if(maxheap.size()>k)
            maxheap.pop();
        if(minheap.size()>k)
            minheap.pop();
    }
     v.push_back(minheap.top());
     v.push_back(maxheap.top());
   
    
    return v;
}

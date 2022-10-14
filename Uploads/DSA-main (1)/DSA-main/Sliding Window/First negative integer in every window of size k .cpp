// Geeksforgeeks practice problem
// Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
                                                 
    vector<long long> v;
    list<long long> l;
    long long i=0,j=0;
    
    while(j<N)
    {
        if(A[j]<0) 
           l.push_back(A[j]);
        if(j-i+1 < K) 
            j++;
        else if((j-i+1) == K)
        {
            if(l.size()==0)
               v.push_back(0);
            else
               v.push_back(l.front());
             
            if(A[i]<0)
              l.pop_front();
            
            i++;
            j++;
        }
           
    }
    return v;
}

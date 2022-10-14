// Leetcoe and Geeksforgeeks problem
// Leetcode Link:  https://leetcode.com/problems/sliding-window-maximum/
// GeeksforGeeks Link: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

        vector<int> maxSlidingWindow(vector<int>& nums, int k) 
       {
        int i=0, j=0;
        int n=nums.size();
        list<int> l;
        vector<int> v;
        while(j<n)
        {
            if(l.size() == 0)
                l.push_back(nums[j]);
            else
            {
                while(l.size()>0 && l.back()<nums[j])
                    l.pop_back();
                l.push_back(nums[j]);
            }
            if(j-i+1 < k)
                j++;
            else if(j-i+1 == k)
            {   if(l.front()!=nums[i])
                 {
                   v.push_back(l.front());
                   j++;
                   i++;
                 }
           
               else if(l.front()==nums[i])
               {
                    l.pop_front();
                    v.push_back(l.front());
                    i++;
                    j++;
               }
            }
        }
        return v;
    }

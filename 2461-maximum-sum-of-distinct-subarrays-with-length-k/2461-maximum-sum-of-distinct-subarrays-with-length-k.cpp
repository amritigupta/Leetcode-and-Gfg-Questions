class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        long long sum=0;
        long long res=0;
        
        for(int i=0; i<k; i++)
        {
            sum+=nums[i];
            m[nums[i]]++; // counting the frequency of each first k elements
        }
        
        if(m.size()==k)
            res=sum;
        
        
        for(int i=k; i<nums.size(); i++)
        {
           // sliding the window one by one and updating the sum accordingly
            sum+=nums[i]; 
            sum-=nums[i-k];
            m[nums[i]]++;
            m[nums[i-k]]--;
            
           // if frequency of elements becomes zero, remove the elements from map
            if(m[nums[i-k]]==0)
                m.erase(nums[i-k]);
            
            // update the result with maximum of result and sum only when map size is equal to length of subarrays
            if(m.size()==k)
                res=max(res,sum);
        }
        
        return res;
        
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left;
        vector<int> right(n);
        int prod=1;
        for(auto it: nums){
            prod*=it;
            left.push_back(prod);
        }
        prod=1;
        for(int i=n-1; i>=0; i--){
            prod*=nums[i];
            right[i]=prod;
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int product = 1;
            if(i>=1) product*=left[i-1];
            if(i<=n-2) product*=right[i+1];
            ans[i]=product;
        }
        return ans;
    }
};
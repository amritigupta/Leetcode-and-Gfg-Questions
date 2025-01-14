class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int sum=0;
        vector<int> pre(n);
        for(int i=0; i<n; i++){
            sum+=nums[i];
            pre[i]=sum;
        }
        int ans = sum; 
        int minval=1e4;

        for(int i=0; i<pre.size(); i++){

            if(nums[i]>0)ans=max(ans, max(pre[i]-minval, pre[i]));
            else ans=max(ans, nums[i]);

            minval=min(minval, pre[i]);
        }

        return ans;
    }
};
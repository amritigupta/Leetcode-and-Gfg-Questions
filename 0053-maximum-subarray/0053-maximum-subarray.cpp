class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // o(n) space
        // int n = nums.size();
        // if(n==1) return nums[0];

        // int sum=0;
        // vector<int> pre(n);
        // for(int i=0; i<n; i++){
        //     sum+=nums[i];
        //     pre[i]=sum;
        // }
        // int ans = sum; 
        // int minval=0;

        // for(int i=0; i<pre.size(); i++){

        //     if(nums[i]>0)ans=max(ans, pre[i]-minval);
        //     else ans=max(ans, nums[i]);

        //     minval=min(minval, pre[i]);
        // }

        // return ans;


        //o(1) space
        int n = nums.size();
        int sum=0;
        int ans=INT_MIN;
        for(auto it: nums){
            sum+=it;
            ans=max(ans, sum);
            if(sum<0) sum=0;
        }
        return ans;
    }
};
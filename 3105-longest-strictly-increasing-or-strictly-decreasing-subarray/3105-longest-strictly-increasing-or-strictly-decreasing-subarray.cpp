class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=1;
        int n = nums.size();
        int ans = 1;
        int curr=1;


        while(i<n){
            if(nums[i]>nums[i-1]){
                curr++;
                i++;
            }
            else{     
                ans=max(ans, curr);
                curr=1;
                i++;
            }
        }
        ans=max(ans, curr);

        i=1;
        curr=1;
        while(i<n){
            if(nums[i]<nums[i-1]){
                curr++;
                i++;
            }
            else{     
                ans=max(ans, curr);
                curr=1;
                i++;
            }
        }

        ans=max(ans, curr);

     
        return ans;
    }
};

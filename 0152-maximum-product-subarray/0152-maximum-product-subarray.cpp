class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre=1;
        int suf=1;
        int premax= INT_MIN;
        int sufmax= INT_MIN;

        for(int i=0; i<n; i++){
            pre*=nums[i];
            premax=max(premax, pre);

            if(pre==0) pre=1;
            
        }

        for(int i=n-1; i>=0; i--){
            suf*=nums[i];
            sufmax=max(sufmax, suf);

            if(suf==0) suf=1;
        }

        return max(premax, sufmax);
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left(n);
        vector<int> right(n);

        int k=1;
        for(int i=0; i<n; i++){
            k*=nums[i];
            left[i]=k;
        }

        k=1;
        for(int j=n-1; j>=0; j--){
            k*=nums[j];
            right[j]=k;
        }

        for(int i=0; i<n; i++){
            ans[i]=1;
            if(i!=0) ans[i]*=left[i-1];
            if(i!=n-1) ans[i]*=right[i+1];
        }

        return ans;

    }
};
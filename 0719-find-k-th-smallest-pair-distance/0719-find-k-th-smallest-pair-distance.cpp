class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxdiff=nums[n-1]-nums[0];
        
        vector<int> mpp(maxdiff+1, 0);

        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                mpp[abs(nums[i]-nums[j])]++;
            }
        }
        int cnt=0;
        int ans;
        for(int i=0; i<maxdiff; i++){
            cnt+=mpp[i];
            if(cnt>=k){
                ans = i;
                break;
            }
        }

        return ans;

    }
};
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int left = j+1;
                int right = n-1;
                
                while(left < right){
                    int sum = nums[left]+nums[right];
                    if(sum==newTarget){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left<right && nums[left]==nums[left-1]){
                            left++;
                        }
                        while(left<right && nums[right]==nums[right+1]){
                            right--;
                        }
                    }
                    else if(sum<newTarget){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        
        return ans;
    }
};
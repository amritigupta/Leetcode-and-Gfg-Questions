class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target1 = target - nums[i];
            for(int j=i+1; j<n; j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                long long target2 = (long long)target1-(long long)nums[j];
                int left = j+1;
                int right = n-1;
                
                while(left < right){
                    int sum = nums[left]+nums[right];
                    if(sum==target2){
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
                    else if(sum<target2){
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
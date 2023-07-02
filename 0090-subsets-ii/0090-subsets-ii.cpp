class Solution {
    vector<vector<int>> ans;
    
    void sub(vector<int> &nums, int i, vector<int> temp)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }

        
        //taking nums[i]
        temp.push_back(nums[i]);
        sub(nums, i+1, temp);
        temp.pop_back();
        
                
        //not taking nums[i]
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        
        sub(nums, i+1, temp);
    }
    
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;       
        sub(nums, 0, temp); // or sub(nums, 0, vector<int> {});
        return ans;
    }
};

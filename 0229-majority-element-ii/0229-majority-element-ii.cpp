class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        unordered_map <int, int> mpp;
        for(int i=0; i<n ; i++){
            mpp[nums[i]]++;
        }
        
        for (auto it: mpp){
            if (it.second > n/3){
                v.push_back(it.first);
            }
        }
        
        return v;
    }
};
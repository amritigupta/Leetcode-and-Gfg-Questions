class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++m[nums[i] & nums[j]];
            }
        }
        
        for (int k = 0; k < n; ++k) {
            for (auto& mm : m) {
                if ((nums[k] & mm.first) == 0) count += mm.second;
            }
        }
        
        return count;
    }
};
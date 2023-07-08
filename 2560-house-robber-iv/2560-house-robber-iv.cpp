class Solution {
public:
    bool isPossible(int m, vector<int>& nums, int k) {
        int i=0;
        while (i<nums.size()) {
            if (nums[i] <= m) {
                i+=2;
                k--;
            }
            else i++;

            if (k==0) return true;
        }
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        
        while (l<r) {
            int m = (l + r) / 2;
            if (isPossible(m, nums, k))
                r = m;
            else
                l = m+1;
        }
        return r;
    }
};

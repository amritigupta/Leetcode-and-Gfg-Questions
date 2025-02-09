class Solution {
public:
    int mod = 1e9+7;

    int rev(int n){
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int x = stoi(s);
        return x;
    }
    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]-rev(nums[i])]++;
        }

        long long ans=0;

        for(auto it: mpp){
            ans+=1ll*(it.second)*(it.second-1)/2;
            ans%=mod;
        }

        return ans;
    }
};
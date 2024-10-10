class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        multimap<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp.insert({nums[i], i});
        }

        vector<int> v;
        for(auto it: mpp){
            cout<<it.second<<" ";
            v.push_back(it.second);
        }
        cout<<endl;

        int mini = INT_MAX;
        int ans = INT_MIN;
        for(int i=0; i<v.size(); i++){
            ans=max(ans, v[i]-mini);
            mini=min(mini, v[i]);
        }
        if(ans>=0) return ans;
        else return 0;
    }
};
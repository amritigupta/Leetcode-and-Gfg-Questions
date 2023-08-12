class Solution {
public:
vector<int> intersection(vector<vector<int>>& nums) {
    vector<int> ans;
    map<int,int> mp;
    int m=nums.size();
    for(int i=0;i<m;i++){
        int n=nums[i].size();
        for(int j=0;j<n;j++)
            mp[nums[i][j]]++;
    }
    
    for(auto i:mp)
        if(i.second==m)    
            ans.push_back(i.first);
    
    return ans;
  }
};
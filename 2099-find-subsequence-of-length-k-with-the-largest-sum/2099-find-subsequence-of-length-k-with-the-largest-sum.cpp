class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        for(int i=0; i<nums.size(); i++){
            v.push_back({nums[i], i});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(auto it : v){
            pq.push(it);
            if(pq.size()>k){
                pq.pop(); //min element removed
            }
        }
        
        vector<pair<int,int>> temp;
        while(!pq.empty()){
            temp.push_back({pq.top().second,pq.top().first});
            pq.pop();
        }
        
        sort(temp.begin(), temp.end());
        vector<int> ans;
        for(auto p: temp){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
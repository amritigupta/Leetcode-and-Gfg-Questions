class Solution {

    void f(int idx,vector<int>& candidates, int target,  vector<vector<int>> &ans, vector<int> &v){
        if(target<0){
            return;
        }
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(idx==candidates.size()){
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if(i!=idx && candidates[i]==candidates[i-1]){
                continue;
            }
            v.push_back(candidates[i]);
            f(i+1,candidates,target-candidates[i],ans,v );
            v.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        f( 0, candidates, target, ans , v);
        return ans;
    }
};
class Solution {
    void f(int ind, int target, vector<int>& arr,  vector<vector<int>> &ans, vector<int> &ds, int &n){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind; i<n; i++){
            if(arr[i]>target){ //arr[i] > target
                break;
            }
            
            if(i>ind && arr[i]==arr[i-1]){ //dont take duplicates
                continue;
            }
            
            ds.push_back(arr[i]);
            f(i+1, target-arr[i], arr, ans, ds, n);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        vector<int> ds;
        
        int n = arr.size();
        f(0,target,arr,ans,ds,n);
        
        return ans;
    }
};
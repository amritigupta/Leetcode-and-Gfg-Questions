class Solution {
public:
    // APPROACH 1

    
    void perm(vector<int>&ds,vector<int>&nums,vector<vector<int>>&ans,vector<int> &vis){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                ds.push_back(nums[i]);
                vis[i]=1; //mark visited
                perm(ds,nums,ans,vis);
                vis[i]=0; //mark not visited
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int> vis(nums.size(), 0);
        
        perm(ds,nums,ans,vis);
        return ans;
    }

};

// class Solution {
// public:
//     vector<vector<int>>v;
//     void solve(vector<int>&a,int idx)
//     {
//         if(idx >= a.size())
//         {
//             v.push_back(a);
//             return;
//         }
//         for(int i = idx; i < a.size(); i++)
//         {
//             swap(a[i],a[idx]);
//             solve(a,idx+1);
//             swap(a[i],a[idx]);
//         }
//     }

//     vector<vector<int>> permute(vector<int>& a) {
//         vector<int>p;
//         solve(a,0);
//         return v;
//     }
// };

//     // APPROACH 2
// class Solution {
// public:
    
//     void perm(int index,vector<int>&nums,vector<vector<int>>&ans){
//         if(index==nums.size()){
//             ans.push_back(nums);
//             return;
//         }
//         for(int i= index;i<nums.size();i++){
//             swap(nums[index],nums[i]);
//             perm(index+1,nums,ans);
//             swap(nums[index],nums[i]);
            
//         }
//     }
    
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>>ans;
//         perm(0,nums,ans);
//         return ans;
//     }
// };
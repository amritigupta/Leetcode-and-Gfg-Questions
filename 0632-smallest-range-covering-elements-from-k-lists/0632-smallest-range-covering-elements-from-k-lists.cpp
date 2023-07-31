typedef pair< int, pair<int,int>> pi;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        int maxi=INT_MIN;
        for(int i=0; i<k ; i++){
            maxi = max(maxi, nums[i][0]);
            pq.push({nums[i][0], {i, 0}});
        }
        
        int range = INT_MAX;
        vector<int> ans(2, -1);
                    
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int mini = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(maxi - mini < range){
                range = maxi-mini;
                ans[0]=mini;
                ans[1]=maxi;
            }
            
            if(col<nums[row].size()-1){
                maxi = max(maxi, nums[row][col+1]);
                pq.push({nums[row][col+1] , {row, col+1}});
            }
            else{
                break;
            }
        }
                    
        return ans;
    }
};
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mpp;
        unordered_map<int,int> balltocolor;
        vector<int> ans;
        for(auto it: queries){
            int ball = it[0];
            int color = it[1];
            if(balltocolor.find(ball)!=balltocolor.end()){
                    mpp[balltocolor[ball]]--;
                    if(mpp[balltocolor[ball]]==0) mpp.erase(balltocolor[ball]);
            }
            mpp[color]++;
            balltocolor[ball]=color;
            ans.push_back(mpp.size());
        }
        return ans;
    }
};
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minval = arrays[0][0];
        int maxval = arrays[0].back();
        int maxdistance=INT_MIN;

        for(int i=1; i<arrays.size(); i++){
            maxdistance = max(maxdistance, max(abs(maxval - arrays[i][0]), abs(arrays[i].back()-minval)));

            maxval = max(maxval, arrays[i].back());
            minval = min(minval, arrays[i][0]);
        }

        return maxdistance;
    }
};
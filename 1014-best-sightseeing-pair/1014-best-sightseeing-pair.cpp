class Solution {
public:
    // O(n) SC
    // int maxScoreSightseeingPair(vector<int>& values) {
    //     int n = values.size();
    //     vector<int> leftmax(n, 0);
    //     leftmax[0]=0;
    //     int ans = 0;
    //     for(int i=1; i<n; i++){
    //         int idx = leftmax[i-1];
    //         int temp1 = values[i]+values[idx]-abs(i-idx);
    //         int temp2 = values[i]+values[i-1]-1;
    //         if(temp1>temp2){
    //             ans = max(ans, temp1);
    //             leftmax[i]=idx;
    //         }
    //         else{
    //             ans = max(ans, temp2);
    //             leftmax[i]=i-1;
    //         }
    //     }

    //     return ans;
    // }

    // O(1) SC
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int leftmax = values[0]+0;
        for(int j=1; j<values.size(); j++){
            int score = leftmax + values[j] - j;
            ans = max(ans, score);
            leftmax = max(leftmax, values[j]+j);
        }
        return ans;
    }
};
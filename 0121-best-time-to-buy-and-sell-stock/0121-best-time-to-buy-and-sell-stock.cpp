class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minvar= INT_MAX;
        int maxprofit=0;
        for(int i=0; i<n; i++){
            minvar=min(minvar, prices[i]);
            maxprofit=max(maxprofit, prices[i]-minvar);
        }
        return maxprofit;
    }
};
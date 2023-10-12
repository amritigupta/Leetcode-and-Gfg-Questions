class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        
        int pre = 1;
        int suf = 1;
        
        int maxi = INT_MIN;
        
        for(int i=0; i<n ; i++){
            if(pre==0) pre=1; //start again
            if(suf==0) suf=1; //start again
            
            pre = pre*arr[i];
            suf = suf*arr[n-i-1];
            
            maxi = max(maxi,max(pre,suf));
        }
        
        return maxi;
    }
};

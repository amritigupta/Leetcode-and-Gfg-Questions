
class Solution {
public:
   bool checkpossible(string s1 ,string s2){
       int s1s = s1.size();
       int s2s = s2.size();
        if(s1s != s2s + 1) return false;
       
        int first = 0;
        int second = 0;
        while(first < s1s){
            if( s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }

        if(first == s1s && second == s2s) return true;
        else return false;
    }

    static bool cmp(string s1 ,string s2){
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end(),cmp);
        vector<int> dp(n,1);
        int maxi = 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                // prev = arr[j]
                // curr = arr[i]
                if(checkpossible(arr[i] , arr[j]) && 1 + dp[j] > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};
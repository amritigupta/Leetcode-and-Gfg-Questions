class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0;
        int j=0;
        int n = s.size();
        unordered_map<char,int> mpp;
        int cnt=0;
        while(j<n){
            mpp[s[j]]++;
            while(mpp['a'] && mpp['b'] && mpp['c']){
                cnt+=n-j;
                mpp[s[i]]--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};

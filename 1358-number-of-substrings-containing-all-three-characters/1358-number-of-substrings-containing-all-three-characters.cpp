class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i=0, j=0, cnt=0;
        unordered_map<char,int> mpp;
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
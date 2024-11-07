class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s.size()==1) return 1;
         int i=0;
         int j=0;
         int n = s.size();
         int maxi = 0;
         unordered_map<char,int> mpp;
         while(j<n){
            mpp[s[j]]++;
            while(mpp[s[j]]>1){
                mpp[s[i]]--;
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
         }

         return maxi;
    }
};
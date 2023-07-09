class Solution {
public:
    int lengthOfLongestSubstring(string s) {      
        int n = s.length();
        int i=0; 
        int j=0;
        int maxi=0;
        unordered_map<char,int> mpp;
        if(s.size()==1){
            return 1;
        }
        while(j<n){
            if(mpp.find(s[j])==mpp.end()){
                mpp[s[j]]++;
                j++;
            }
            else{
 
                maxi = max(maxi, (j-1)-i+1);
                
                mpp[s[i]]--;
                if(mpp[s[i]]==0){
                    mpp.erase(s[i]);
                }
                
                i++;
            }
        }
        maxi = max(maxi, (j-1)-i+1);
        return maxi;
    }
};


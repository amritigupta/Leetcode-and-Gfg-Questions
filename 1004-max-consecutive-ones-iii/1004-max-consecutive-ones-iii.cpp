class Solution {
public:
    int longestOnes(vector<int>& s, int k) {
        int i=0;
        int j=0;
        int n = s.size();
        int ans = 0;
        while(j<n){
            
            if(s[j]==0 && k>=1){
                k--;
            }
            
            else if(s[j]==0 && k==0){
                
                ans=max(ans, (j-1)-i+1);
                cout<<ans<<" "<<i<<" "<<j-1<<endl;
                if(s[i]==0){
                    k++;
                }
                
                i++;
                continue;
            }
            
            j++;
        }
        ans=max(ans, (j-1)-i+1);
        return ans;
    }
};
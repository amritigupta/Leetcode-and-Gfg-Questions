class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0; i<=n ; i++){
            int num = i;
            int cnt=0;
            while(num>0){
                int bit = num&1;
                if(bit) cnt++;
                num=num>>1;
            }
            ans[i]=cnt;
        }
        
        return ans;
    }
};
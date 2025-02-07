class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;

        for(auto it: nums){
            xorr^=it;
        }

        int i=0;
        while(true){
            if(xorr&1==1) break;
            xorr>>=1;
            i+=1;
        }
        //ith bit is set to 1
        // cout<<i<<endl;

        int x1 =0;
        int x2=0;
        for(auto it: nums){
            if((it>>i & 1) == 0){
                x1^=it;
                // cout<<1<<it<<endl;
            }
            else{
                x2^=it;
                // cout<<2<<it<<endl;
            }
        }

        return {x1, x2};
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n= nums.size();
        vector<int> f(32,0);
        
        for(int e : nums){
            for(int i=0; i<32; i++){
                if(e & (1<<i)){
                    f[i]++;
                }
            }
        }
        
        //construct result
        int res = 0;
        for(int i=0; i<32; i++){
            if(f[i]%3 == 1){
                res += (1<<i); // 1<<i == 2^i
            }
        }
        
        return res;
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bitindex=0; bitindex<=31; bitindex++){
            int cnt=0;
            // cout<<bitindex<<endl;
            for(int i=0; i<n; i++){
                // cout<<nums[i]<<" "<<(1<<bitindex)<<" ";
                int x = nums[i]&(1<<bitindex);
                // cout<<x<<endl;
                if((nums[i]&(1<<bitindex))){
                    cnt++;
                }
                
            }
            // cout<<endl<<bitindex<<" "<<cnt<<endl;
            if(cnt%3!=0){
                ans = ans|(1<<bitindex);
            }
        }
        return ans;
    }
};
class Solution {
public:
    // long long countBadPairs(vector<int>& nums) {
    //     int n = nums.size();
    //     unordered_map<int,int> mpp;
    //     long long ans=0;
    //     for(int i=0; i<n; i++){
    //         mpp[nums[i]-i]++;
    //         if((i+1)-mpp[nums[i]-i]<=0){
    //             continue; //dont add anything
    //         }
    //         else{
    //             ans+=(i+1-(mpp[nums[i]-i]));
    //         }
    //     }
    //     return ans;
    // }


    // another method
    // total pairs = n*(n-1)/2 --> using nc2
    // invalid = total - valid pairs 

     long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]-i]++;
        }
        long long tot = 1ll*n*(n-1)/2;
        long long validcnt=0;
        for(auto it: mpp){
            //it.second c 2
            validcnt+=1ll*(it.second-1)*(it.second)/2;
        }

        return tot-validcnt;
     }   
};
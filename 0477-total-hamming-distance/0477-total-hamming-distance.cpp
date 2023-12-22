
        // 4 =  0 1 0 0
        // 14 = 1 1 1 0 
        // 2 =  0 0 1 0
        
        //      1 2 2 0
        //.     2 2 2 0 = 
        
       // 4 =  0 1 0 0
       // 14 = 1 1 1 0 
       // 4 =  0 1 0 0
        
      //  =    1 3 1 0
      // =.    2 0 2 0
        
       // 4 =  0 1 0 0
       // 14 = 1 1 1 0 
       // 4 =  0 1 0 0
        // 2 = 0 0 1 0
 // =             1 3 2 0
 //     =         3 3 4 0
        

// Then, if there are n integers in the array and k of them have a particular bit set and (n-k) do not, then that bit contributes nx(n-k) to the hamming distance. (Because for each of the 'k' numbers, we have 1 of the (n-k) numbers, that have a different bit and the number of ways to select 1 from k and (n-k) numbers is (kC1)x((n-k)C1)




class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size(), ans=0;
        for(int i=0;i<32;i++){
            int count=0; //Count of the no.of elements that have the 'i'th bit set
            for(int k=0;k<n;k++){
                count += (nums[k]>>i)&1;
            }
            ans += count*(n-count);
        }
        return ans;
    }
};

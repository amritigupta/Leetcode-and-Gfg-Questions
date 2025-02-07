class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res=0;
        for(auto it: nums){
            res^=it;
        }
        cout<<res<<endl;
        //res contains xor of the two elements
        // if a bit is set in res
        // it means that bit is set in one of the 2 integers

        // lets find that integer now
        int x1 = 0;
        int x2 = 0;

        // 6 = 1 1 0 
        // 0 0 1
        // 0 1 0
        // 0 0 1
        // 0 1 1
        // 0 1 0
        // 1 0 1

        for(int i=31; i>=0; i--){

            if((res&(1<<i))!=0){
                for(int num: nums){
                    if((num&(1<<i))!=0){
                        x1^=num;        
                    }
                    else{
                        x2^=num;
                        
                    }
                }

                break;
            }
            
        }

        vector<int> v = {x1, x2};
        return v;
    }
};

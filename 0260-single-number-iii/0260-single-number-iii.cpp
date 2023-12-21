class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> p;
        int x=0;
        for(int i=0; i<nums.size();i++){
            x=x^nums[i];
        }
        
        int pos = 0;
        int temp = x;
        
        while((temp&1)==0){
            pos++;
            temp=temp>>1;
        }
        
        int seta = 0;
        int setb = 0;
        int mask = (1<<pos);
        for(int i=0; i<nums.size(); i++){
            if((mask&nums[i])>0){
                seta = seta^nums[i];
            }
            else{
                setb=setb^nums[i];
            }
        }
        p.push_back(seta);
        p.push_back(setb);
        
        return p;
    }
};
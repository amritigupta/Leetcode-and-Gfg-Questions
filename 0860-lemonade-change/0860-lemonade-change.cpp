class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mpp;
        mpp[5]=0;
        mpp[10]=0;
        mpp[20]=0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i]==5){
                mpp[5]++;
                continue;
            }
            else if(bills[i]==10){
                if(mpp[5]>0){
                    mpp[10]++;
                    mpp[5]--;
                    continue;
                }
                else return false;
            }
            else{
                if(mpp[10]>0 && mpp[5]>0){
                    mpp[10]--;
                    mpp[5]--;
                    mpp[20]++;
                    continue;
                }
                else if(mpp[5]>2){
                    mpp[5]=mpp[5]-3;
                    continue;
                }

                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        map<int,int> mymap;

        int x=999;

        for (int i=0; i<n; i++){
            mymap[nums[i]]++;
        }

        for (int i=0; i<nums.size() ;i++){
            if ( mymap[nums[i]] >= (n/2 + 1) ){
                return nums[i];
            }
        }

        return x;
    }
};
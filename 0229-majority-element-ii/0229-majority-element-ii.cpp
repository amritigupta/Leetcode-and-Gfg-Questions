class Solution {
public:
    
    // SPACE COMPLEXITY : O(N)
//     vector<int> majorityElement(vector<int>& nums) {
//         vector<int> v;
//         int n = nums.size();
//         unordered_map <int, int> mpp;
//         for(int i=0; i<n ; i++){
//             mpp[nums[i]]++;
//         }
        
//         for (auto it: mpp){
//             if (it.second > n/3){
//                 v.push_back(it.first);
//             }
//         }
        
//         return v;
//     }
     // SPACE COMPLEXITY : O(1)
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1=0, cnt2=0, el1=INT_MIN, el2=INT_MIN;
        
        for(int i=0; i<n; i++){
            if(cnt1==0 && nums[i]!=el2){
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=el1){
                cnt2=1;
                el2=nums[i];
            }       
            else if(el1 == nums[i]){
                cnt1++;
            }
            else if(el2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> ls;
        cnt1=0; 
        cnt2=0;
        for(int i=0; i<n ; i++){
            if(el1==nums[i]) cnt1++;
            if(el2==nums[i]) cnt2++;
        }
        
        int mini = int(n/3)+1;
        if (cnt1>=mini) ls.push_back(el1);
        if (cnt2>=mini) ls.push_back(el2);
        
        sort(ls.begin(), ls.end());
        return ls;
    }
};
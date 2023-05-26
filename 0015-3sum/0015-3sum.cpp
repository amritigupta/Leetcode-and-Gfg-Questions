class Solution {
public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>> st;
        
//         for(int i=0; i<n ; i++){
//             set<int> hashset;
//             for(int j=i+1; j<n ; j++){
                
//                 int third = -(nums[i] + nums[j]);
//                 if (hashset.find(third)!=hashset.end()){
//                     vector<int> temp = {third, nums[i], nums[j]};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(nums[j]);
//             }
//         }
        
        
//         vector<vector<int>> ans(st.begin(), st.end());
//         return ans;
//     }
    
 vector<vector<int>> threeSum(vector<int>& nums) {
    int n= nums.size();
    vector<vector<int>> ans;
    set<vector<int>> s;
    sort(nums.begin(),nums.end());
    int l,r,sum;

    for(int i=0;i<n;i++){
        l=0,r=n-1;       // i is the pivot index. l and r are the right and left side index.
		
        while(l<i && r>i){  
            sum= nums[l]+nums[i]+nums[r];
            if(sum ==0){   // A triplet is found. It might also be a repeated triplet. 
                s.insert(vector<int>{nums[l],nums[i],nums[r]});   // to avoid duplicate triplet
                l++,r--;    // { l, i , r} combination is taken  
            } else if (sum <0)
                l++;   // moving towards larger element will increase the sum. 
            else
                r--;   //moving towards smaller element will decrease the sum. 
        }
    }
    for(auto i:s)
        ans.push_back(i);   // push all the elements in the set to a 2D vector. 
    return ans;
}
};
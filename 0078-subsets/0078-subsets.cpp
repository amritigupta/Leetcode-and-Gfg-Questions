// //USING RECURSION
// class Solution {
//     vector<vector<int>> ans;
    
//     void sub(vector<int> &nums, int i, vector<int> temp)
//     {
//         if(i==nums.size())
//         {
//             ans.push_back(temp);
//             return;
//         }
//         //not taking nums[i]
//         sub(nums, i+1, temp);
        
//         //taking nums[i]
//         temp.push_back(nums[i]);
//         sub(nums, i+1, temp);
//     }
    
    
//     public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> temp;       
//         sub(nums, 0, temp); // or sub(nums, 0, vector<int> {});
//         return ans;
//     }
// };

  // Bit Manipulation

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int num = (1<<n);
        int i = 0;
        
        while(i<num)
        {
            vector<int> temp;
            for(int j=0; j<n; j++)
            {
                if(i & 1<<j)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
            i++;
        }
        
        return ans;
    }
};
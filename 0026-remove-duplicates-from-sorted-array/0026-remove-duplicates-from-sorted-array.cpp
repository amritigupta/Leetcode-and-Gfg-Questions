class Solution {
public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int> s;
//         int n = nums.size();
//         for (int i=0; i<n ; i++){
//             s.insert(nums[i]);
//         }
//         int index = 0;
//         for(auto it: s){
//             nums[index] = it;
//             index++;
//         }

//         return index;
//     }
    
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        for(int j=1; j<n; j++){
            if(arr[i]!=arr[j]){
                arr[i+1]=arr[j];
                i++;
            }
        }
        
        return (i+1);
    }
};


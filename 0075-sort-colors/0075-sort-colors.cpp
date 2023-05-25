class Solution {
public:
    // BETTER SOLUTION
//     void sortColors(vector<int>& nums) { 

//         map<int, int> mymap;
//         int n= nums.size();

//         for (int i=0; i<n; i++){
//             mymap[nums[i]]++;
//         }

     
//         int j=0;

//         for (int i=0; i<mymap[0]; i++){
//             nums[j++]=0;
//         }

//         for (int i=0; i<mymap[1]; i++){
//             nums[j++]=1;
//         }

//         for (int i=0; i<mymap[2]; i++){
//             nums[j++]=2;
//         }

//     } 
    
    // OPTIMAL SOLUTION
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int low=0;
        int mid =0;
        int high = n-1;
        
        while(mid<=high){
            if (arr[mid]==0){
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
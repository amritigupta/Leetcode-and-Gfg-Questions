class Solution {
public:
    // int findKthPositive(vector<int>& arr, int k) {
    //     for (auto a : arr) if (a <= k) k++;
    //     return k;
    // }
    
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size()-1;
        
        while(low<=high){ 
            int mid = low+(high-low)/2;
            int missing = arr[mid]-(mid+1);
            
            if(missing < k){
                low = mid+1;
            }
            else{
                high = mid-1;
             }
        }
        
        if(high<0){
            return k;
        }
        
        int missing = k-(arr[high]-(high+1));
        return arr[high]+missing;
    }   
};
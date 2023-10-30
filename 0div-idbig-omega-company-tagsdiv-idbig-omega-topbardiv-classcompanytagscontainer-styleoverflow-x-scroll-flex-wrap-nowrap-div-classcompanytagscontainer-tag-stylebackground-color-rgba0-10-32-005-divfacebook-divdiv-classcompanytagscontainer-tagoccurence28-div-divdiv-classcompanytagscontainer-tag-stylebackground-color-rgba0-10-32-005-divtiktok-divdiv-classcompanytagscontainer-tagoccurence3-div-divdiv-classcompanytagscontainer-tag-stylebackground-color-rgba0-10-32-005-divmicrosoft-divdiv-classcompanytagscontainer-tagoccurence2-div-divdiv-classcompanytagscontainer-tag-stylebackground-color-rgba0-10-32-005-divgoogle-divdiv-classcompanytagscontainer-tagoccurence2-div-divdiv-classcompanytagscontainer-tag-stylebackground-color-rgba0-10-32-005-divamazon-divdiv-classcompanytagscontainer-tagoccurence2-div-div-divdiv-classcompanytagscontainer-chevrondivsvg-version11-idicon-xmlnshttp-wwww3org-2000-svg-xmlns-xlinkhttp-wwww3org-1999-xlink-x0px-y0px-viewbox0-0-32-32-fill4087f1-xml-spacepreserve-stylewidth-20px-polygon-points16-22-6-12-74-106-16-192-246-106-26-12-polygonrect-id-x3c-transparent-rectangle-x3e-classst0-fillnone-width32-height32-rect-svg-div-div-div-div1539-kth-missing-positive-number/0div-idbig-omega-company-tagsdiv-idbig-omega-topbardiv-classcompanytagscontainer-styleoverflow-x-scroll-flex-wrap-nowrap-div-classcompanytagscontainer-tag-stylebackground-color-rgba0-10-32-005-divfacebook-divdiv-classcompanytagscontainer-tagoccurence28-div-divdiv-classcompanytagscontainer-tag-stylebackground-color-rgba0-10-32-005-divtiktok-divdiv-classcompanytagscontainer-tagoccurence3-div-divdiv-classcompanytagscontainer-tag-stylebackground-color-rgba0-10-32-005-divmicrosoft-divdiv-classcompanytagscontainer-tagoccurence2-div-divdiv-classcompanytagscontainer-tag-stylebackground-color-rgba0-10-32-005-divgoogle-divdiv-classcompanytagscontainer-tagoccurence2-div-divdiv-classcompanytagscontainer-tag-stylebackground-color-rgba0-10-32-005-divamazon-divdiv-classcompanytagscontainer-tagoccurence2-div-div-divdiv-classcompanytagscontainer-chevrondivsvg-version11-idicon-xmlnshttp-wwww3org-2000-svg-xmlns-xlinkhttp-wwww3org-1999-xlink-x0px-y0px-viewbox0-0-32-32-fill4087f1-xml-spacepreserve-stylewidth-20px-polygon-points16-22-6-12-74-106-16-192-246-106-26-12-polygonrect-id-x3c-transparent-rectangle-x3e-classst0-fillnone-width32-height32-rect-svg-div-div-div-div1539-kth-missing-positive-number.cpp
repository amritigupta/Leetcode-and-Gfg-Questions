class Solution {
public:
    // int findKthPositive(vector<int>& arr, int k) {
    //     for (auto a : arr) if (a <= k) k++;
    //     return k;
    // }
    
    
        
    // 2 3 4 7 11
    
    // 1 1 1 3 6 (missing array)
    
    // mid = 2
    // missing = 1 < k
    // low = 3 , high = 4.
    // mid = 3
    // missing = 3 < k
    // low = 4 high = 4
    // missing=6 > k, high = 4-1 = 3, low = 4
    // 7 = 3 , + 2

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
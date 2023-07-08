class Solution {
public:
    /* we want to check can we make m bouquets at a day of mid or not */
    bool check(vector<int> &arr, int mid, int m, int k){
        int subarray = 0;
        int total = 0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] <= mid){
                total++;
            }
            else{
                if(total == k){
                    subarray++;
                }
                total = 0;
            }
            if(total == k){
                subarray++;
                total = 0;
            }
        }
        if(subarray >= m) return true;
        return false;
    }
    
    int minDays(vector<int>& arr, int m, int k) {
        /* if m*k < total no. of flows then we can't make m bouquets */
        if(((long long)m*(long long)k) > arr.size()) return -1;
        
        int l = *min_element(arr.begin(), arr.end()), r = *max_element(arr.begin(), arr.end());
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(arr, mid, m, k)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
	
};
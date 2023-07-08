class Solution {
    bool ispos(int mid, vector<int>& arr, int m, int k){
        int subarray=0;
        int total=0;
        for(int i=0; i<arr.size(); i++){
            if(mid>=arr[i]){
                total++;
                        if(total==k){
                subarray++;
                total=0;
            }
            }
            else{
                if(total>=k){
                    subarray++;
                }
                total=0;
            }

        }
       
        if(subarray<m) return false;
        else return true;
    }
public:
    int minDays(vector<int>& arr, int m, int k) {

        int l = *min_element(arr.begin(),arr.end()) ;
        int r = *max_element(arr.begin(),arr.end()) ;
        int ans = -1;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            if (ispos(mid,arr,m,k)){
                ans = mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return ans;
    }
};
class Solution {
    /* 3 2 2 4 1 4*/
  
    bool ispos(int capacity, int threshold, vector<int>& arr){
        int ans =0;
        int days=1;
        int c = capacity;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]<=c){
                if(i!=arr.size()-1){
                c=c-arr[i];
                }
            }
            else{
                if(i!=arr.size()-1){
                     days++;
                     // cout<<i<<'\t'<<arr[i]<<"\t"<<c<<"\t"<<days<<endl;
                     c=capacity;
                     c=c-arr[i];
                }
            }
            
            if(i==arr.size()-1){
                if(c>=arr[i]){
                    continue;
                }
                else{    
                    // cout<<arr[i]<<"\t"<<c<<"\t"<<days<<endl;
                    days++;
                }
            }
        }

        if(days<=threshold){
            return true;
        }
        else{
            return false;
        }
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int sum=0;
        for(auto it: weights){
            sum+=it;
        }
        int r = sum;
        
        int ans = -1;
    
     
        while(l<=r){
            int mid = l+(r-l)/2;
            if(ispos(mid, days, weights)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
      
        return ans;
    }
};
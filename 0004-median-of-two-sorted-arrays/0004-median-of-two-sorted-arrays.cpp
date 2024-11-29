class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        if(n>m){
            return findMedianSortedArrays(nums2,nums1); //making sure nums1 is always smaller array
        }
        
        int low=max(0, (n+m+1)/2 - m) ,high=min(n, (n+m+1)/2 ); //n is max elements u can take from nums1 array
        int left=(n+m+1)/2; 
        while(low<=high){
            int mid1 = (low+high)/2; //1 //elements taken from nums1
            int mid2= left-mid1;   // 1  //elements taken from nums2
            int l1=INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2=INT_MAX;
            
            if(mid1 < n){
                r1 = nums1[mid1]; //3 
            }
            if(mid2 < m ){
                r2 = nums2[mid2]; //INT_MAX
            }
            if(mid1-1>=0){
                l1 = nums1[mid1-1]; // 1
            }
            if(mid2-1>=0){
                l2 = nums2[mid2-1]; // 2
            }
            
            if (l2<=r1 && l1<=r2){
                if((n+m)%2==1){
                    return (max(l1, l2));
                }
                else return double((max(l1,l2)+min(r1,r2))/2.0);
            }
            
            if(l1>r2){
                high = mid1-1;
            }
            else{
                low=mid1+1;
            }
        }
        return 0;
    }
};

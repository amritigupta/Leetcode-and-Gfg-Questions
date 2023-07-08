class Solution {
public:
    int findMin(vector<int>& nums) {
	
       int n=nums.size();
        int s=0;
		int e=n-1;
		
        while(s<=e){
            int mid=s+(e-s)/2;
            int prev=(mid-1+n)%n;
            int next=(mid+1)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return nums[mid];
            }
            else if(nums[e]>=nums[mid]) e=mid-1;
            else if(nums[s]<=nums[mid]) s=mid+1;
        }
		
        return 0;
    }
};
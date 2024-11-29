class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n,0);
        vector<int> rightmax(n,0);

        int lmax = 0;
        for(int i=0; i<n; i++){
            lmax = max(height[i], lmax); 
            leftmax[i] = lmax;        
        }

        int rmax=0;
        for(int i=n-1; i>=0; i--){
            rmax=max(rmax, height[i]);
            rightmax[i]= rmax;
        }

        int ans = 0;
        for(int i=1; i<n-1; i++){
            ans += max(0,min(leftmax[i], rightmax[i])-height[i]);
        }
        return ans;
    }
};

// [0,1,0,2,1,0,1,3,2,1,2,1]
// [0,1,1,2,2,2,2,3,3,3,3,3]
// [1,2,2,2,3,3,3,3,3,3,3,3]
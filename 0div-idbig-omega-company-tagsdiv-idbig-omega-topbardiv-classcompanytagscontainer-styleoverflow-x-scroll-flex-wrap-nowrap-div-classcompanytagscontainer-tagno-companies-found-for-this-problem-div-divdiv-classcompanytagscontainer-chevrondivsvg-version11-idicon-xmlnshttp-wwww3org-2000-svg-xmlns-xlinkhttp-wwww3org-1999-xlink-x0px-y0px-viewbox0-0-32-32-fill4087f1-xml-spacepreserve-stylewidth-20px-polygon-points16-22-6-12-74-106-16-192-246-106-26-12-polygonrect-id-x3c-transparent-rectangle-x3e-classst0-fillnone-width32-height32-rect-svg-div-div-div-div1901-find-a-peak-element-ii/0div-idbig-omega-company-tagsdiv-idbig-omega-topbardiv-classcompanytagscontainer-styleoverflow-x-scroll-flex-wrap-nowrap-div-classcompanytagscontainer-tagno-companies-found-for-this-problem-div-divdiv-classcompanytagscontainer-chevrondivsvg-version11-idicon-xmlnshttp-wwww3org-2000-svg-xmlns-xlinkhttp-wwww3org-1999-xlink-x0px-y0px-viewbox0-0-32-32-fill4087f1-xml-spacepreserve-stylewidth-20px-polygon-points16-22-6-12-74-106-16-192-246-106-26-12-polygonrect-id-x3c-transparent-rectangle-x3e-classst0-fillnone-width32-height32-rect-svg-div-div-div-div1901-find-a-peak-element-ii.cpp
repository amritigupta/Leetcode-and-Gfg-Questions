class Solution {
    int findmaxindex(vector<vector<int>>& mat, int n , int m , int col){
        int maxvalue = -1;
        int idx = -1;
        for(int i=0; i<n; i++){
            if(mat[i][col]>maxvalue){
                maxvalue = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low= 0, high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int maxrowidx = findmaxindex(mat, n, m, mid);
            int left = mid-1>=0 ? mat[maxrowidx][mid-1]:-1;
            int right = mid+1<m ? mat[maxrowidx][mid+1]:-1;
            if(mat[maxrowidx][mid]>left && mat[maxrowidx][mid]>right){
                return {maxrowidx, mid};
            }
            else if(mat[maxrowidx][mid]<left){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};
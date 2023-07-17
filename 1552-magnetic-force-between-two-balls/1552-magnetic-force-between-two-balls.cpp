//aggresive cows problem

class Solution {
    bool ifpossible(vector<int>& position, int m, int mid){
        int ballcount = 1;
        int lastpos = position[0];
        
        for(int i=0;i<position.size();i++){
            if(position[i]-lastpos >= mid){
                ballcount++;
                if(ballcount==m) return true;
                lastpos = position[i];
            }
        }
        
        return false;
    }
    
public:
    
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(),position.end());
        int s = 0;
        int e = position[position.size()-1];
        int ans = -1;
        
        while(s<=e){
            int mid = s +(e-s)/2;
            if(ifpossible(position,m,mid)){
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return ans;
        
    }
};
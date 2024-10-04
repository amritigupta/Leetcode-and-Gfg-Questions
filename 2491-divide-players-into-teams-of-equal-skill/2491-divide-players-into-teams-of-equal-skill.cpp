class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        // 1 2 3 3 4 5

        int n = skill.size();

        sort(skill.begin(), skill.end());
        int mini = skill[0];
        int maxi = skill[n-1];

        int s = mini+maxi;

        int i=1;
        int j=n-2;

        while(i<=j){
            if(skill[i]+skill[j]==s){
                i++;
                j--;
            }
            else break;
        }

        if(i>j){
            int x=0;
            int y=n-1;
            long long ans=0;
            while(x<=y){
                ans+=skill[x]*skill[y];
                x++;
                y--;
            }
            return ans;
        }

        return -1;
    }
};
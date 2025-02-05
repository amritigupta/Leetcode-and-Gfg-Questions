class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        int mismatch=0;
        vector<int> v;
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i]){
                mismatch++;
                v.push_back(i);
                if(mismatch>2) return false;
            }
        }

        if(mismatch==1) return false;
        if(mismatch==0) return true;

        //mismatch is 2 now

        if((s1[v[0]]==s2[v[1]]) && (s1[v[1]]==s2[v[0]])) return true;
        return false;
    }
};
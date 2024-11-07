class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int,int> mpp;
        for(auto it: t){
            mpp[it]++;
        }

        // TTA

        // TOMTTA

        int n = s.size();
        int count = mpp.size();
        int i=0;
        int j=0;
        int ans=INT_MAX;
        int start=0;

        while(j<n && i<n){
           if(mpp.find(s[j]) != mpp.end()){
                mpp[s[j]]--;

                if(mpp[s[j]]==0)
                    count--;
            }
            if(count==0){
                while(count==0 && i<n){
                    if(ans>(j-i+1)){
                        ans = j-i+1;
                        start= i;
                    }

                    if(mpp.find(s[i])!=mpp.end()){
                        mpp[s[i]]++;
                        if(mpp[s[i]]>0){
                            count++;
                        }
                    }

                    i++;
                }
            }

            j++;
        }

        if(ans!=INT_MAX){
            return s.substr(start,ans);
        }
        else{
            return "";
        }
    }
};
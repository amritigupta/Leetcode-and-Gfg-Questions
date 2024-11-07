class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0;
        int n = s.size();
        int maxi=0;
        int maxcharcnt = 0;
        vector<int> freq(27,0);
        while(j<n){ //o(n)
            freq[s[j]-'A']++;
            maxcharcnt = max(maxcharcnt, freq[s[j]-'A']);
            while((j-i+1 - maxcharcnt)>k){ //i runs from 0 to N o(n)
                freq[s[i]-'A']--;
                maxcharcnt=0;
                // THIS UPDATION IS OPTIONAL (EXPLAINED BELOW)
                for(int p=0; p<=26; p++){ //o(26) == o(1)
                    maxcharcnt = max(maxcharcnt, freq[p]);
                }
                i++;
            }
            maxi = max(maxi, j-i+1);
            j++;
        }

        return maxi;
    }

    //optimizing
    // WHEN WE RUN THE O(26) LOOP TO UPDATE MAXCHARCNT
    // WE KNOW THE MAXCHARCNT WILL OBVIOUSLY DECREASE FROM THE PREVIOUS MAXCHARCNT
    //
    // observe that maxlen(j-i+1) - maxcharcnt should be <= K right
    // so what happens when u want to increase ur maxlen
    // u will want to increase maxcharcnt
    // but in the o(26) loop we wud be decreasing maxcharcnt which eventually wouldnt give us an answer bigger than our current maxlen
    // so we can just not update it to reduce from O(2N*26) TO O(2N)
};
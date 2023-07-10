
class Solution {
public:

    
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int max_len = 0,  max_majority_occur_till_now = 0, start = 0;
        for (int end = 0; end < s.size(); end++) {
            char ch = s[end] - 'A';
            count[ch]++;
             max_majority_occur_till_now = max( max_majority_occur_till_now, count[ch]);
            
            if (end - start - max_majority_occur_till_now + 1 > k) {
                count[s[start] - 'A']--;
                start++;
            }
            max_len = end - start + 1;
        }
        return max_len;
    
    }
};
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        int letters[26] = {0};
        
        for (char c: allowed)
            letters[c-'a'] = 1;
        
        bool found = true;
		
        for (string str: words) {
            for (char c: str) 
                if (letters[c-'a'] == 0) {
                    found = false;
                    break;
                }
            
            if (found)
                cnt++;
            found = true;
        }
		
        return cnt;
    }
};
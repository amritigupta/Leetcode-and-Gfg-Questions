class Solution {
    unordered_map <string , int> mpp;
    vector<vector<string>>  ans;
private:
    void dfs(string word, vector<string> &seq, string beginWord){
        if (word == beginWord){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int sz = beginWord.size();

        int steps = mpp[word];
           for (int i=0; i<sz; i++){
                char original = word[i];
                for (char ch ='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if (mpp.find(word)!=mpp.end() && mpp[word]==steps-1){
                        seq.push_back(word);
                        dfs(word, seq, beginWord);
                        seq.pop_back();
                    }
                }
                word[i]=original;
           }
        
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set <string> st(wordList.begin(), wordList.end());
        queue <string> q;
        q.push(beginWord);
        st.erase(beginWord);
        mpp[beginWord]=1;
        int sz = beginWord.size();
        while (!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if (word == endWord){break;}

            for (int i=0; i<sz; i++){
                char original = word[i];
                for (char ch ='a'; ch<='z'; ch++){
                    word[i]=ch;
                    if (st.count(word)>0){
                        q.push(word);
                        st.erase(word);
                        mpp[word]=steps+1;
                    }
                }
                word[i]=original;
            }
        }
        if (mpp.find(endWord)!=mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq, beginWord);
        }

        return ans;
    }
};
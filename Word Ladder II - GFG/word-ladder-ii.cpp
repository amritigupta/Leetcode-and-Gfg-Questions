//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
/*
class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        
        unordered_set <string> st(wordList.begin(), wordList.end());
        queue <vector<string> > q;
        q.push({beginWord});
        
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        
        int level =0;
        
        vector<vector<string>> ans;
        
        while (!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            //erase all words used in previous levels to transform
            if (vec.size()>level){
                level++;
                for (auto it: usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            
            string word = vec.back();
            
            if (word==endWord){
                if (ans.size()==0){
                    ans.push_back(vec);
                }
                else if (ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            
            for (int i=0; i<word.size(); i++){
                char original = word[i];
                for (char c ='a'; c<='z'; c++){
                    word[i]=c;
                    if (st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                        
                    }
                }
                
                word[i]= original;
            }
        }
        return ans;
    }
};*/
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
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {

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

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends
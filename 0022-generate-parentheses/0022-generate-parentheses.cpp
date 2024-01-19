/*class Solution {
    
    void help(int curr, unordered_set<string> &st, string &s, unordered_map<char, int> &mpp, int n){
        if(curr==2*n){
            st.insert(s);
            return;
        }
        
        
        if(mpp['(']>mpp[')']) return;

        for(auto it: mpp){
            int cnt = it.second;
            while(cnt--){
                mpp[it.first]--;
                s+=it.first;
                
                help(curr+1, st, s, mpp, n);
                s.pop_back();
                mpp[it.first]++;
            }
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        unordered_map <char, int> mpp;
        for(int i=0; i<n; i++){
            mpp['(']++;
            mpp[')']++;
        }
        
        unordered_set<string> st;
        string s;
        int curr=0;
        help(curr,st,s, mpp, n);
        
        vector<string> ans;
        for(auto it: st) ans.push_back(it);
        
        return ans;
    }
};
*/

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    dfs(n, n, "", ans);
    return ans;
  }

 private:
  void dfs(int l, int r, string&& path, vector<string>& ans) {
    if (l == 0 && r == 0) {
      ans.push_back(path);
      return;
    }

    if (l > 0) {
      path.push_back('(');
      dfs(l - 1, r, move(path), ans);
      path.pop_back();
    }
    if (l < r) {
      path.push_back(')');
      dfs(l, r - 1, move(path), ans);
      path.pop_back();
    }
  }
};
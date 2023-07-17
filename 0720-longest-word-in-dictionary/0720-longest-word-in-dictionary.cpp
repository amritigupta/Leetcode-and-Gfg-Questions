class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string>st(begin(words),end(words));
        sort(begin(words),end(words));
        //for(auto i:words) cout<<i<<".";
        //vector<string>same;
        int maxcnt=-1;
        string str="";
        for(int i=0;i<words.size();i++)
        {   
            int cnt=0;
            if(isvalid(words[i],st,cnt) and cnt>maxcnt){
                maxcnt=cnt;
                str=words[i];
            }
        }
        return str;
    }
    
    bool isvalid(string word,unordered_set<string>&st,int &cnt)
    {   
        if(word.size()==1 and st.count(word)) return true;//if size of word become 1 and it exist in set return
        word.pop_back();//removing last character form the word
        if(st.count(word)){
            cnt++;
            return isvalid(word,st,cnt);
        }
        return false;//if above condition fails return false
    }
};
/*
struct Node{
    
    Node* links[26];
    bool  flag;
    bool containKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }  
    Node* get(char ch){
        return links[ch-'a'];
    }
    bool isEnd(){
        return flag;
    }
    void setEnd(){
        flag=true;
    }
    bool getFlag(){
        return flag;
    }  
    
};


class Trie{
    private:
    Node* root;
    
    public:
    Trie(){
        root=new Node();
    }
    
    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            
        }
        node->setEnd();
    }
    
    bool checkLongest(string &word){
        Node* node=root;
        bool ans=true;
        
        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i]))
            {
              // check if flag is true for its reference node (ninga where g's reference is false)
              node=node->get(word[i]);
              if(node->isEnd()==false) return false;
            }
            else{
                return false;
            }    
        }   
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        
        string ans="";
        Trie* mytrie=new Trie();
        
        for(auto it:words){
            mytrie->insert(it);
        }
        
        for(auto it:words){
            if(mytrie->checkLongest(it) ){
                if(it.length()>ans.length())
                    ans=it;
                else if(it.length()==ans.length() && it<ans)
                    ans=it;
            }
        }
        
        return ans;
    }
   
}; */
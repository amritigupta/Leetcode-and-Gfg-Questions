class Solution {

struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
    
};

    
class Trie {
  private: 
  Node * root;

  public:
    Trie() {
      root = new Node();
    }
 
  public:
    void insert(int num) {
      Node * node = root;
    
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1; //whether it is 0 or 1 at ith bit in num
        if (!node -> containsKey(bit)) { //if not present add it
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
    
  public:
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1; //check ith bit in num
        if (node -> containsKey(!bit)) { //if opposite bit is present
          maxNum = maxNum | (1 << i); //maxnum = maxnum || (1<<i)
          node = node -> get(!bit); // go to next node
        } 
        else {
          node = node -> get(bit); // go to next node 
        }
      }
      return maxNum;
    }
};

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin() , nums.end());
        vector<pair<int,pair<int,int>>> oq;
        int q = queries.size();
        for(int i=0; i<q; i++){
            oq.push_back({queries[i][1], {queries[i][0], i}}) ; // ai, xi, i
        }
        sort(oq.begin() , oq.end());
        vector<int> ans(q,0);
        int ind=0;
        int n = nums.size();
        Trie trie;
        
        for(int i=0; i<q; i++){
            int ai = oq[i].first;
            int xi = oq[i].second.first;
            int qindex= oq[i].second.second;
            
            while(ind < n && nums[ind]<= ai){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind==0){
                ans[qindex]=-1;
            }
            else{
                ans[qindex]= trie.findMax(xi);
            }
        }
        
        return ans;
    }
};
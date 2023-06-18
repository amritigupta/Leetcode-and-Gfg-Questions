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
    int findMaximumXOR(vector<int>& nums) {
       Trie trie;
       int n = nums.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
          trie.insert(nums[i]);
          maxi = max(maxi, trie.findMax(nums[i]));
        }
        
       return maxi;       
    }
};
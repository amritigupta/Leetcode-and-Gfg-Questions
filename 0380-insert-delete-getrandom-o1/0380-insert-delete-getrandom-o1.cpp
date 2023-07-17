class RandomizedSet {
    
private:
    vector<int> nums;
    unordered_map<int, int> m;
    
public:
  
    RandomizedSet() {
        
    }
  
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        nums.emplace_back(val);
        // m[val] = index
        m[val] = nums.size() - 1;
        return true;
    }
    
   
    bool remove(int val) {
        if (m.find(val) == m.end()) 
            return false;
        // val = 20
        // m[val]=1
        // last = nums.back() ie = 50
        // m[last]= m[val] // 50 -> 1
        // nums[m[val]]=last // store at 1 index - 50
        // nums.pop_back() delete 50 from nums (we already added it at 1 index so dont worry)
        // m.erase(val) //erase 20 from ur map
        
        
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
 
    int getRandom() {
        return nums[rand() % nums.size()];
    }

};


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
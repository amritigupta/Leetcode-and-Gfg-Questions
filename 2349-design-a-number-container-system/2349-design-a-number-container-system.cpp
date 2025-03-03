class NumberContainers {
private:
    unordered_map<int,int> mp1;
    unordered_map<int,set<int>>mp2;
public:
    void change(int index, int number) {
        int temp = -1;
        if(mp1.count(index)) temp = mp1[index];
        mp1[index] = number;
        if(temp != -1) mp2[temp].erase(index);
        mp2[number].insert(index);
    }
    
    int find(int number) {
        if(mp2[number].size()){
            return *(mp2[number].begin());
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
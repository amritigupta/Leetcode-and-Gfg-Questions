class FrontMiddleBackQueue {
public:
    vector<int> v;
    int cnt = 0;
    
    
    FrontMiddleBackQueue() {
        v.clear();

    }
    
    void pushFront(int val) {
        if(v.empty()) v.push_back(val);
        else
        v.insert(v.begin(),val);
        cnt++;
    }
    
    void pushMiddle(int val) {
        v.insert(v.begin()+cnt/2,val);
        cnt++;
    }
    
    void pushBack(int val) {
        v.push_back(val);
        cnt++;
    }
    
    int popFront() {
        if(v.empty()) return -1;
        int t = v[0];
        v.erase(v.begin());
        cnt--;
        return t;
    }
    
    int popMiddle() {
        if(v.empty()) return -1;
        int mid = cnt/2;
        if(cnt % 2 == 0){
         mid = v[cnt/2-1];
        v.erase(v.begin()+cnt/2-1);
        }
        else{
             mid = v[cnt/2];
        v.erase(v.begin()+cnt/2);
        }
        cnt--;
        return mid;
    }
    
    int popBack() {
        if(v.empty()) return -1;
        int b = v[cnt-1];
        v.pop_back();
        cnt--;
        return b;
    }
};
/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
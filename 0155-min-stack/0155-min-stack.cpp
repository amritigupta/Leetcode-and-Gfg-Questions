// USING O(N)+O(N)
// class MinStack {
// 	public:
// 		stack<int>s,minKeeper;
    
// 		void push(int val) {
// 			s.push(val); // push val in stack

// 			if(minKeeper.size()==0||val<=minKeeper.top()){//push in when empty or lesser than current minElement
// 				minKeeper.push(val);
// 			}
// 		}

// 		void pop() {
// 			if(minKeeper.top() == s.top())//pop when last element was min element 
// 				minKeeper.pop();
// 			s.pop();
// 		}

// 		int top() {//return top of stack
// 			return s.top();
// 		}

// 		int getMin() {//return top of minKeeper
// 			return minKeeper.top();
// 		}
// 	};

//Optimal Solution
// Using o(n)

class MinStack {
public:
    vector< pair<int,int> > s;
	
    MinStack() { }
    
    void push(int val) {
        if(s.empty())
            s.push_back({val,val});
        else
            s.push_back({val,min(s.back().second,val)});    
    }
    
    void pop() { s.pop_back(); }
    
    int top() { return s.back().first; }
    
    int getMin() { return s.back().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
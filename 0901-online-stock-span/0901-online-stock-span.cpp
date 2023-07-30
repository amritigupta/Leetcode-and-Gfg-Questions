class StockSpanner {
    stack<pair<int, int>> s;
    int index;
public:
    StockSpanner() {
        index=-1;
    }
    
    int next(int price) {
        index+=1;
        while(!s.empty() && s.top().second<=price){
            s.pop();
        }
        
        if(s.empty()){
            s.push({index, price});
            return index+1;
        }
        
        int result = s.top().first;
        s.push({index, price});
        return index-result;
    }
};

 /*     
class StockSpanner {
public:

    // declare a stack of pair {price, count}

    // count will keep track of no. of consecutive elements less than or equal to price

    stack<pair<int, int>> st;

    StockSpanner() {
        
    }
    
    
    int next(int price) {
        
        int count = 0;

        // find no. of elements less than or equal to curr price

        while(st.empty() == false && st.top().first <= price)
        {
            // update count

            count += st.top().second;

            // pop the smaller element

            st.pop();
        }

        // increment the count for curr price

        count++;

        // push the {price, count} into stack

        st.push({price, count});

        return count;
    }
};

*/
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
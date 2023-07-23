
class Solution {
public:
    vector<int> nextsmallerelement(vector<int>& heights){
        vector<int> res;
        stack<int> st;
        st.push(-1);
        for(int i=heights.size()-1; i>=0; i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            res.push_back(st.top());
            st.push(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    vector<int> prevsmallerelement(vector<int>& heights){
        vector<int> res;
        int n = heights.size();
        stack<int> st;
        st.push(-1);
        for(int i=0; i<n; i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            res.push_back(st.top());
            st.push(i);
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next = nextsmallerelement(heights);
        vector<int> prev = prevsmallerelement(heights);
        
        int maxi=INT_MIN;
        for(int i=0; i<n; i++){
            if(next[i]==-1){
                next[i]=n;
            }
            maxi=max(maxi, heights[i]*(next[i]-prev[i]-1));
        }
        return maxi;
    }
};
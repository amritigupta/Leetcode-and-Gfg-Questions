class Solution {
public:
    bool check(stack<char> st, string part){
        int n = part.length();
        int j=n-1;
        while(j>=0 && st.top()==part[j]){
            st.pop();
            j--;
        }
        if(j==-1){
            return true;
        }
        return false;
    }
    
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int m = part.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            st.push(s[i]);
            if(st.size()>=m){
                // cout<<check(st,part)<<endl;
                if(check(st, part)){
                    int temp=part.size();
                    while(temp>0){
                        st.pop();
                        temp--;
                    }
                }
            }
        }
        
        string answer="";
        while(!st.empty()){
            char ch = st.top();
            st.pop();
            answer+=ch;
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
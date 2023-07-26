class Solution {
public:
    //  using stacks
    
// int longestValidParentheses(string s) {
// 	int MAX = 0;  // denotes length of maximum valid parentheses
// 	stack<int> stk;
// 	stk.push(-1); // bottom of stack will always hold index preceding to potential start of valid parentheses
// 	for(int i = 0; i < size(s); i++)
// 		if(s[i] == '(') stk.push(i);            
// 		else{                
// 			stk.pop();
// 			if(stk.empty()) stk.push(i);
// 			else MAX = max(MAX, i - stk.top());
// 		}        
// 	return MAX;
// }
    
    // using dp
    int longestValidParentheses(string s) {
        int n = s.size(); 
        vector<int> dp(n+2);
        dp[0]=0;
        dp[1]=0;
        for(int i=1; i<n; i++){
            if(s[i]=='('){
                dp[i+1]=0;
            }
            
            else if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i+1]=dp[i-1]+2;
                }
                else{ //ie when, s[i-1]==')'
                    int j = i-dp[i]-1;
                    if(j<0){
                        dp[i+1]=0;
                    }
                    if(j>=0 && s[j]=='('){
                        dp[i+1]=dp[i]+dp[j]+2;
                    }
                }
            }
        }
        
        int maxi=0;
        
        for(int i=0; i<=n; i++){
            maxi=max(maxi, dp[i]);
        }
        
        return maxi;
    }
   // int longestValidParentheses(string s) {
   //          if(s.length() <= 1) return 0;
   //          int curMax = 0;
   //          vector<int> longest(s.size(),0);
   //          for(int i=1; i < s.length(); i++){
   //              if(s[i] == ')'){
   //                  if(s[i-1] == '('){
   //                      longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
   //                      curMax = max(longest[i],curMax);
   //                  }
   //                  else{ // if s[i-1] == ')', combine the previous length.
   //                      if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
   //                          longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
   //                          curMax = max(longest[i],curMax);
   //                      }
   //                  }
   //              }
   //              //else if s[i] == '(', skip it, because longest[i] must be 0
   //          }
   //          return curMax;
   //      }
};
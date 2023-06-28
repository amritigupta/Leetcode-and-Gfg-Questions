class Solution 
{
public:
    string removeDuplicates(string s, int k) 
    {
// each element in the stack will store the character and how many times it occurs continously in the string
        stack<pair<char,int>>stk;
        
        for(int i=0;i<s.length();i++)
        {
            // if stack is empty push the character
            if(stk.empty())
            {
                stk.push({s[i],1});
            }
            else
            {
         // else check if we have visitied the current character just before then increment it's count
                if(stk.top().first==s[i])
                {
                    stk.top().second++;
                }
                // otherwise push it to the stack with count = 1
                else
                {
                    stk.push({s[i],1});
                }
            }
            // if we've visited k consecuitve charcaters which are same then remove it from the stack
            if(!stk.empty() && stk.top().second==k)
            {
                stk.pop();
            }
            
        }
        
        // finally form the resulting string with the help of remaining characters in the stack
        string ans="";
        while(!stk.empty())
        {
            ans+=string( stk.top().second , stk.top().first );
            stk.pop();
        }
 // reverse the string cause in stack characters were in reverse order. So to get the correct the string reverse it.
        reverse(ans.begin(),ans.end());
        // finally return the answer
        return ans;
    }
};
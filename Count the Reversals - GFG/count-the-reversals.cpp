//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    if (s.size()%2 != 0)
         return -1;
         
     int open=0; int close=0; 
     stack<char> st;
     
     for (int i=0; i< s.length(); i++){
         if(s[i]=='{'){
             st.push(s[i]);
             open++;
         }
         else if(s[i]=='}'){
             if(!st.empty() && st.top()=='{'){
                 st.pop();
                 open--;
             }
             else{
                 close++;
             }
         }
     }
     
     if((open+close)%2!=0){
         return -1;
     }
     
     else return  (close+1)/2+(open+1)/2;
}
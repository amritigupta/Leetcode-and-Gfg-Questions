//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
    int chartodigit(char s){
        return s-'0';
    }
    
    char digittochar(int n){
        return n+'0';
    }
    
  public:
    string findSum(string X, string Y) {
        // Y is always larger than X

        int i=0;
        while(X[i]=='0' && X.length()>1){
            X.erase(i, 1);
            // cout<<X<<endl;
        }
        i=0;
        
        while(Y[i]=='0' && Y.length()>1){
            Y.erase(i, 1);
        }
        // cout<<X<<" "<<Y<<endl;
        
        if(X.length()>Y.length()){
            return findSum(Y, X);
        }     
        
        string result="";
        reverse(X.begin(), X.end());
        reverse(Y.begin(), Y.end());
        
        int carry=0;

        for(int i=0; i<X.length(); i++){
            int n1 = chartodigit(X[i]);
            int n2 = chartodigit(Y[i]);
            int sum = n1+n2+carry;
            carry = sum/10;
            char c = digittochar(sum%10);
            result+=c;
        }
        
        for(int i=X.length(); i<Y.length(); i++){
            int n2 = chartodigit(Y[i]);
            int sum = n2+carry;
            carry = sum/10;
            char c = digittochar(sum%10);
            result+=c;           
        }
        
        // cout<<result<<endl;
        
        if(carry){
            result+='1';
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends
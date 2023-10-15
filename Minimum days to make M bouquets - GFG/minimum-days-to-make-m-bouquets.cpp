//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool isvalid(int M, int K, vector<int> &bloomDay, int mid){
        vector<int> check;
        int tempcnt=0;
        
         int cnt = 0;
         for(int i=0; i<bloomDay.size(); i++){
             if(bloomDay[i]>mid){
                 tempcnt=0;
                 continue;
             }
             if(tempcnt<K && bloomDay[i]<=mid){
                 tempcnt++;
                 if(tempcnt==K){
                   cnt++;
                   tempcnt=0;
                 }
             }

         }
         
         if(cnt>=M){
             return true;
         }
         
         return false;
    }
  public:
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
      
      // k is fixed
      // m is fixed
      
      // return min days 
      int low = 1;
      int res = -1;
      int high = *max_element(bloomDay.begin(), bloomDay.end());
      while(low<=high){
          int mid = low+(high-low)/2;
          if (isvalid(M,K, bloomDay, mid)){
              res = mid;
              high = mid-1;
          }
          else{
              low = mid+1;
          }
      }
      
      return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        // subset means no order
        // subsequence means in order
        int n= arr.size();
        vector<int>dp(n,1) ,hash(n); // taking dp vector and the track vector;

        int maxi=1; // count the length of the  subset 
        int lastIndex=0; // the index where  our last element of the subset is store
        sort(arr.begin(), arr.end());
// sort an array we will sorted because the question is asking only for subset 
        for( int i=0;i<n;i++){  
            hash[i]=i;
            for( int prev=0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 && 1+dp[prev]>dp[i]){
// if it will divisible by that and the length of the subset is greater than that
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
            maxi=dp[i];
            lastIndex=i;
            }
        } 
// this whole part is to store the element in  temp and return it
// now print the subset in an array
         vector<int> temp;
         temp.push_back(arr[lastIndex]);
         while(hash[lastIndex]!=lastIndex){
             lastIndex= hash[lastIndex];
             temp.push_back(arr[lastIndex]);
         }
         return temp;
    }

    
};
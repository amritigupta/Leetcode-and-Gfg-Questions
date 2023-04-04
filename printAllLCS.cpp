#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// Function to return all LCS of substrings `X[0…m-1]`, `Y[0…n-1]`
vector<string> LCS(string X, string Y, int m, int n, auto &dp)
{
    // if the end of either sequence is reached
    if (m == 0 || n == 0)
    {
        // create a vector with an empty string and return
        return {""};
    }
 
    // if the last character of `X` and `Y` matches
    if (X[m - 1] == Y[n - 1])
    {
        // ignore the last characters of `X` and `Y` and find all LCS of substring
        // `X[0…m-2]`, `Y[0…n-2]` and store it in a vector
        vector<string> lcs = LCS(X, Y, m - 1, n - 1, dp);
 
        // append current character `X[m-1]` or `Y[n-1]` to all LCS of
        // substring `X[0…m-2]` and `Y[0…n-2]`
        for (string &str: lcs) {        // don't remove `&`
            str.push_back(X[m - 1]);
        }
 
        return lcs;
    }
 
    // we reach here when the last character of `X` and `Y` don't match
 
    // if a top cell of the current cell has more value than the left cell,
    // then ignore the current character of string `X` and find all LCS of
    // substring `X[0…m-2]`, `Y[0…n-1]`
 
    if (dp[m - 1][n] > dp[m][n - 1]) {
        return LCS(X, Y, m - 1, n, dp);
    }
 
    // if a left cell of the current cell has more value than the top cell,
    // then ignore the current character of string `Y` and find all LCS of
    // substring `X[0…m-1]`, `Y[0…n-2]`
 
    if (dp[m][n - 1] > dp[m - 1][n]) {
        return LCS(X, Y, m, n - 1, dp);
    }
 
    // if the top cell has equal value to the left cell, then consider
    // both characters
 
    vector<string> top = LCS(X, Y, m - 1, n, dp);
    vector<string> left = LCS(X, Y, m, n - 1, dp);
 
    // merge two vectors and return
    top.insert(top.end(), left.begin(), left.end());
    // copy(left.begin(), left.end(), back_inserter(top));
 
    return top;
}

void LCSLength(string X, string Y, int m, int n, auto &dp)
{
    // first row and first column of the dp table are already 0
 
    // fill the lookup table in a bottom-up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // if current character of `X` and `Y` matches
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // otherwise, if the current character of `X` and `Y` don't match
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

set<string> LCS(string X, string Y)
{
    int m = X.length(), n = Y.length();
 
    // lookup[i][j] stores the length of LCS of substring `X[0…i-1]` and `Y[0…j-1]`
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
 
    // fill lookup table
    LCSLength(X, Y, m, n, dp);
 
    // find all the longest common subsequences
    vector<string> v = LCS(X, Y, m, n, dp);
 
    // since a vector can contain duplicates, "convert" it to a set
    set<string> lcs(v.begin(), v.end());
    
    // to copy a vector to a set use set<string> lcs(v.begin(), v.end())
 
    // return set containing all LCS
    return lcs;
}

int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
 
    set<string> lcs = LCS(X, Y);
 
    // print set elements
    for (string str: lcs) {
        cout << str << endl;
    }
 
    return 0;
}

// OUTPUT IS:
// BCAB
// BCBA
// BDAB

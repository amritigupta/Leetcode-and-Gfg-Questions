class Solution {
public:
    long long subArrayRanges(vector<int>& A) {
    long ans = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        int mx = A[i], mn = A[i];
        for (int j = i + 1; j < n; j++)
        {
            mx = max(mx, A[j]);
            mn = min(mn, A[j]);

            ans += (mx - mn);
        }
    }
    return ans;
}
};
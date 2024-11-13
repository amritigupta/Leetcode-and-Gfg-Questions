class Solution {
public:
    int minOperations(int n) {
        vector<int> arr; 
        for (int i = 0; i < n; i++) {
            arr.push_back((2 * i) + 1);
        }
        
        int ans = 0;  
        
        // Traverse through the first half of the array and calculate the number of operations needed
        for (int j = 0; j < (n + 1) / 2; j++) {
            // Add the difference divided by 2 between the corresponding elements from the start and end
            ans += (arr[arr.size() - j - 1] - arr[j]) / 2;
        }
        return ans;
    }
};
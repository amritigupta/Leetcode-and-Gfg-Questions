class Solution {
    vector<int> prevgreaterelement(vector<int> &nums){
        stack<int> st;
        st.push(-1);
        int n = nums.size();
        vector<int> res;  
        for(int i=0; i<n; i++){
            while(st.top()!=-1 && nums[st.top()]<nums[i]){
                st.pop();
            }
            res.push_back(st.top());
            st.push(i);
        }
        return res;        
    }
    vector<int> nextgreaterelement(vector<int> &nums){
        stack<int> st;
        int n = nums.size();
        st.push(n);
        
        
        vector<int> res;    
        for(int i=n-1; i>=0; i--){
            while(st.top()!=n && nums[st.top()]<=nums[i]){
                st.pop();
            }
            res.push_back(st.top());
            st.push(i);
        }
        reverse(res.begin(), res.end());
        return res;        
    }
    vector<int> nextsmallerelement(vector<int> &nums){
        stack<int> st;
        int n = nums.size();
        st.push(n);
      
        vector<int> res;
        for(int i=n-1; i>=0; i--){
            while(st.top()!=n && nums[st.top()]>=nums[i]){
                st.pop();
            }
            res.push_back(st.top());
            st.push(i);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<int> prevsmallerelement(vector<int> &nums){
        stack<int> st;
        st.push(-1);
        int n = nums.size();
        vector<int> res;
        for(int i=0; i<n; i++){
            while(st.top()!=-1 && nums[st.top()]>nums[i]){
                st.pop();
            }
            res.push_back(st.top());
            st.push(i);
        }
        return res;
    }
    
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>prevSmaller = prevsmallerelement(nums);
        vector<int>prevGreater = prevgreaterelement(nums);
        vector<int>nextSmaller = nextsmallerelement(nums);
        vector<int>nextGreater = nextgreaterelement(nums);
        
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int prevRangeCount = i - prevSmaller[i];
            int nextRangeCount = nextSmaller[i] - i;
            long long minSubarrayCount = (long long)prevRangeCount * nextRangeCount;
            ans = ans - (long long)(nums[i] * minSubarrayCount);
            
            int prevRangeCount1 = i - prevGreater[i];
            int nextRangeCount1 = nextGreater[i] - i;
            long long maxSubarrayCount = prevRangeCount1 * nextRangeCount1;
            ans = ans + (long long)(nums[i] * maxSubarrayCount);
        }
        return ans;      
        
    }
};
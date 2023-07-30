class Solution {
public:
void solve(int i, int sum, vector<int>&nums, vector<int>&sums){
    if(i==nums.size()) {
        sums.push_back(sum);
        return;
    }
    
    solve(i+1,sum,nums,sums);
    solve(i+1,sum+nums[i],nums,sums);
}

int minAbsDifference(vector<int>& nums, int goal) {
    vector<int> num1;
    vector<int> num2;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(i<n/2) num1.push_back(nums[i]);
        else num2.push_back(nums[i]);
    }
    
    vector<int> sum1;
    vector<int> sum2;

    solve(0,0,num1,sum1);
    solve(0,0,num2,sum2);
    
    int min_diff=INT_MAX;

    sort(sum2.begin(),sum2.end());
    
    for(auto i: sum1){
        int st=0,en=sum2.size()-1;
        while(st<=en){
            int mid = st+(en-st)/2;
            int sum = i+sum2[mid];
            if(sum==goal) return 0;
            min_diff = min(min_diff,abs(sum-goal));
            
            if(sum<goal){
                st=mid+1;
            }
            else{
                en = mid-1;
            }
        }
    }
    return min_diff;
  }
    
};
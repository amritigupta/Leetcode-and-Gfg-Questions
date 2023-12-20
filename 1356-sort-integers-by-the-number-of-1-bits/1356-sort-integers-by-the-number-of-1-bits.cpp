class Solution {
public:
 int countbit(int n)
    {
        int count=0;
        while(n>0)
        {
            int bit = n&1;
            if(bit) count++;
            n=n>>1;
        }
        return count;
    }
	
vector<int> sortByBits(vector<int>& arr) {
    map<int,vector<int>>mp;
    vector<int>v;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++)
    {
       mp[countbit(arr[i])].push_back(arr[i]); 
    }

    for(auto it:mp)
    {
        for(int a:it.second)
        {
        v.push_back(a);
        }
        
    }
 
    return v;
   }
};
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
    multimap<int,int>mp;
    vector<int>v;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++)
    {
       mp.insert({countbit(arr[i]),arr[i]});
    }

    for(auto it:mp)
    {
        v.push_back(it.second);
    }
 
    return v;
   }
};
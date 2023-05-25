
/*class Solution {
public:
    vector<int> twoSum(vector<int> a, int target) {
        int i;
        map<int,int>mymap;
        map<int,int>::iterator it;
        vector<int>ans;
        for(i=0;i<a.size();i++){
            it=mymap.find(target-a[i]);
                if(it!=mymap.end()){
                     ans.push_back(it->second);
                     ans.push_back(i);
                     break;
                }
            else{
                mymap.insert(make_pair(a[i],i));
            }
        }
        return ans;
    }
}; */

class Solution {
public:
    vector<int> twoSum(vector<int> a, int target) 
    {
        unordered_map<int, int> mpp;

        vector <int> ans;
        int N = a.size();
        
        for (int i=0; i<N; i++){
            if (mpp.find(target - a[i])!=mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[target-a[i]]);
            }
            else{
                mpp.insert(make_pair(a[i],i));
            }
        }

        return ans;
    }
}; 


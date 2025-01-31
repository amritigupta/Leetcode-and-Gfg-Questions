class Solution {
    vector<int> size;
    vector<int> parent;

public:
    int findupar(int v){
        if(parent[v]==v) return v;
        else return parent[v]=findupar(parent[v]);
    }

    void Union(int i, int j){
        int upri=findupar(i);
        int uprj=findupar(j);
        if(upri==uprj) return;
        else{
            if(size[upri]<size[uprj]){
                parent[upri]=uprj;
                size[uprj]+=size[upri];
            }
            else{
                parent[uprj]=upri;
                size[upri]+=size[uprj];                
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mpp;
        unordered_map<int, vector<string>> mpp2;

        int n = accounts.size();
        size.resize(n);
        parent.resize(n);

        for(int i=0; i<n; i++){
            parent[i]=i;
            size[i]=1;
        }

        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mpp.find(accounts[i][j])==mpp.end()){        
                    mpp[accounts[i][j]]=i;
                    mpp2[i].push_back(accounts[i][j]);
                }
                else{
                    Union(i, mpp[accounts[i][j]]);
                    mpp2[i].push_back(accounts[i][j]);
                }
            }
        }

        for(int i=0; i<accounts.size(); i++){
            if(parent[i]!=i){
                int upri=parent[i];
                vector<string> s2 = mpp2[i];
                for(auto it: s2) mpp2[parent[i]].push_back(it);
            }
        }

        vector<vector<string>> ans;
        for(int i=0; i<accounts.size(); i++){
            if(parent[i]==i){
                vector<string> v;
                set<string> st;
                v.push_back(accounts[i][0]); //pushes back John
                vector<string> v2 = mpp2[i];
                for(auto it: v2) st.insert(it);
                for(auto it: st) v.push_back(it);
                ans.push_back(v);
            }
        }    

        return ans;   
    }
};


// 0 - 1
// 2
// 3

// 0 - johnsmith@mail.com, john_newyork@mail.com
// 1 - john00@mail.com, johnsmith@mail.com
// 2 - mary@mail.com 
// 3 - johnnybravo@mail.com


//johnsmith@mail.com - 0
//john_newyork@mail.com - 0

//  john00@mail.com - 1
// johnsmith@mail.com - 1

// mary@mail.com - 2
// johnnybravo@mail.com - 3
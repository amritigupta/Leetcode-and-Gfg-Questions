// DSU HELPS IN DYNAMIC MERGING/CONNECTING

class DisjointSet {
	vector<int> rank, parent;
public:
	DisjointSet(int n) {
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}

	int findupar(int node) {
		if (node == parent[node]) {
			return node;
		}

		return parent[node] = findupar(parent[node]); //path compression
	}

	void unionbyrank(int u, int v) {
		int ulp_u = findupar(u);
		int ulp_v = findupar(v);
		if (ulp_u == ulp_v) {
			// u and v belong to same component
			return;
		}

		if (rank[ulp_u] < rank[ulp_v]) {
			//smaller gets attached to larger
			//rank doesnt change
			parent[ulp_u] = ulp_v;
		}
		else if (rank[ulp_u] > rank[ulp_v]) {
			//smaller gets attached to larger
			//rank doesnt change
			parent[ulp_v] = ulp_u;
		}
		else {
			//attach v to u (or vice versa)
			//incease rank of u by 1 (or vice versa)
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        // cout<<n<<endl;
        unordered_map <string, int> mapmailnode;
        
        for(int i=0; i<accounts.size(); i++){
            for(int j=1 ; j<accounts[i].size(); j++){
                if(mapmailnode.find(accounts[i][j])==mapmailnode.end()){
                    mapmailnode[accounts[i][j]] = i;
                    // cout<<accounts[i][j]<<" "<<i<<endl;
                }
                else{
                    ds.unionbyrank(mapmailnode[accounts[i][j]], i);
                }
            }
        }
        

        unordered_map <int, set<string>> mpp;

        for(int i=0; i<n; i++){
            cout<<i<<" "<<ds.findupar(i)<<endl;
            if(ds.findupar(i)==i){
                if(mpp.find(i)==mpp.end()){
                  set<string> s;
                  for(int j=1; j<accounts[i].size(); j++){
                    s.insert(accounts[i][j]);
                  }
                  mpp[i]=s;
                }
                else{
                  for(int k=1; k<accounts[i].size(); k++){
                    mpp[i].insert(accounts[i][k]);
                    // john's map is added w john00
                   }     
                }
                // john is matched to johnsmith and john_newyork
                // mary with mary
                //john with johnnybravo
            }
            else{
                int ultimateparent = ds.findupar(i); // 1 -> 0

                if(mpp.find(ultimateparent)!=mpp.end()){
                  for(int k=1; k<accounts[i].size(); k++){
                    mpp[ultimateparent].insert(accounts[i][k]);
                    // john's map is added w john00
                   }
                }
                else{
                  set<string> s;
                  for(int j=1; j<accounts[i].size(); j++){
                    s.insert(accounts[i][j]);
                  }
                  mpp[ultimateparent]=s; 
                }
            }
        }
        
        vector<vector<string>> ans;
        for(auto it: mpp){
            vector<string> s;
            s.push_back(accounts[it.first][0]);
            for(auto it2: it.second){
                s.push_back(it2);
            }
            ans.push_back(s);
        }
        
        return ans;
        
    }
 
};
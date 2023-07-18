class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& points) {
        map<int,vector<int>> mappa;
        sort(r.begin(),r.end());
        vector<int> ans;
        for(auto it:r){
            mappa[it[1]].push_back(it[0]);//pushing the x coordinate to the respective mapping of y coordinate
        }
        

        for(auto i:points){
		   //in order to contain the given point.....the y coordinate and x coordinate of rectangle must be
			//greater  than or equal to that of the point.
            auto it = mappa.lower_bound(i[1]);//finding the y coordinates of rectangle that are greater than or
			//equal to y coordinate of the given point.
            
            int k = 0;
            while(it!=mappa.end()){
                auto it1 = lower_bound((*it).second.begin(),(*it).second.end(),i[0]);
				//in the vector finding the lower bound of given x coordinate of the point.
				
                k+=(*it).second.end()-it1;
                it++;
            }
            ans.push_back(k);
        }
        return ans;
    }
};
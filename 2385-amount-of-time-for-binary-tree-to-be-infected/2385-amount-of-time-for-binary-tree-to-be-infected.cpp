/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//BURN TREE QUESTION FROM STRIVER

class Solution {
    void markparents(TreeNode* root,  unordered_map<TreeNode* , TreeNode* > &parent, TreeNode* &target, int start){
        
        queue<TreeNode* > q;
        q.push(root);  
     
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if (it->val == start ){
                target = it;
            }
            
            if(it->left){
                q.push(it->left);
                parent[it->left]=it;
 
            }
            if(it->right){
                q.push(it->right);
                parent[it->right]=it;
       
            }            
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode* > parent;
        unordered_map<TreeNode* , bool> vis;
        
        TreeNode* target;
        markparents(root, parent, target, start);
        
        queue<TreeNode* >q;
        
        q.push(target);
        int time=0;
      
  
        while(!q.empty()){
            
            bool flag =0;
            int size = q.size();
            for(int i=0; i<size; i++){
                
                auto it = q.front();
                q.pop();
                vis[it]=true;

                
               if(it->left && !vis[it->left]){
                q.push(it->left);
                vis[it->left]=true;
                flag=1;
               }
                
               if(it->right && !vis[it->right]){
                q.push(it->right);
                vis[it->right]=true;
                flag=1;
               } 
                
               if (parent[it] && !vis[parent[it]]){
                   q.push(parent[it]);
                   vis[parent[it]]=true;
                   flag=1;
               }
                
               
            } 
            if(flag==1) time++;
            
        }
        return time;
    }
};
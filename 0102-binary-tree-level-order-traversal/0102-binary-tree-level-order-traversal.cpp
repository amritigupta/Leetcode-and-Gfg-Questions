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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>  ans;
        if (root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0 ; i< size; i++){
                auto it = q.front();
                q.pop();
                if (it->left){
                    q.push(it->left);
                }
                if (it->right){
                    q.push(it->right);
                }
                level.push_back(it->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
    
    /* vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        levelorder(root, nodes);
        return nodes;
    }
    

    void levelorder( TreeNode* root, vector<vector<int>>& nodes){
        if (root == NULL){
            return ;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> level;

        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            if (it == NULL && q.size()==0){
                break;
            }
            
            if(it==NULL){
                q.push(NULL);
                nodes.push_back(level);
                level.clear();
                continue;
            }
            
            level.push_back(it->val);
            
            if (!it->left){
                q.push(it->left);
            }
            if (!it->right){
                q.push(it->right);
            }            
        }
    } */
};
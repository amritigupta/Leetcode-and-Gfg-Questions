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

    // USING 1 QUEUE (STRIVER)
    
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        
         vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool left2right=true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            
            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                
                int index = (left2right) ? i : (size-i-1);
                
                row[index]= it->val;
                
                if (it->left) q.push(it->left);
                
                if (it->right) q.push(it->right);
            }
            
            //after this level;
            left2right = !left2right;
            result.push_back(row);
        }
        
        return result;
    }
        
        
    
};
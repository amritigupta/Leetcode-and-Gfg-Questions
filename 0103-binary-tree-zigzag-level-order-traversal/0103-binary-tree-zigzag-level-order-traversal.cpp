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
    
    // USING 2 STACKS
    
//     vector<vector<int>> zigzagLevelOrder(TreeNode *root)
//     {
//         if (root == NULL)
//         {
//             return {};
//         }
        
//         stack<TreeNode *> st1;
//         stack<TreeNode *> st2;
//         vector<vector<int>> v;
//         st1.push(root);
        
//         while (!st1.empty() || !st2.empty())
//         {
//             vector<int> p;
//             while (!st1.empty())
//             {
//                 TreeNode *curr = st1.top();
//                 p.push_back(curr->val);
//                 st1.pop();
//                 if (curr->left != NULL)
//                     st2.push(curr->left);
//                 if (curr->right != NULL)
//                     st2.push(curr->right);
//             }
            
//             if (p.size() != 0)
//                 v.push_back(p);
            
//             vector<int> q;
//             while (!st2.empty())
//             {
//                 TreeNode *curr = st2.top();
//                 q.push_back(curr->val);
//                 st2.pop();
//                 if (curr->right != NULL)
//                     st1.push(curr->right);
//                 if (curr->left != NULL)
//                     st1.push(curr->left);
//             }
//             if (q.size() != 0)
//                 v.push_back(q);
//         }
        
//         return v;
//     }
    
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
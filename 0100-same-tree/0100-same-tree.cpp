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
    
    // RECURSIVE
    
//     bool isSameTree(TreeNode* p, TreeNode* q) {
        
//         if(p==NULL || q==NULL){
//             return p==q;
//         }
        
//         return (p->val ==q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right) );
//     }
    
    // ITERATIVE

    
    bool isSameTree(TreeNode* p, TreeNode* q){
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p,q});
        while(!st.empty()){
            auto it= st.top();
            st.pop();
            
            if (it.first == NULL && it.second == NULL){
                continue;
            }
            
            if (!it.first || !it.second || it.first->val != it.second->val) return false;
            
            st.push({it.first->left, it.second->left});
            st.push({it.first->right, it.second->right});
        }
        
        return true;
    }
};
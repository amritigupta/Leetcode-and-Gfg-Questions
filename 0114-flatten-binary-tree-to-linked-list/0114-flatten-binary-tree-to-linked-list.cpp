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
    // right left root (reverse postorder)
    
public:
    // RECURSIVE
//     TreeNode* prev = NULL;
//     void flatten(TreeNode* node) {
//         if(node== NULL){
//             return;
//         }
        
//         flatten(node->right);
//         flatten(node->left);
        
//         node->right = prev;
//         node->left = NULL;
        
//         prev=node;
//     }
    
    //ITERATIVE
    void flatten(TreeNode* root)
    {
        stack<TreeNode *>st;
        st.push(root);
        while(st.empty()!=true)
        {
            TreeNode *curr = st.top();
            st.pop();
            if(curr==NULL) return;
            if(curr->right!=NULL) st.push(curr->right);
            if(curr->left!=NULL) st.push(curr->left);
            if(st.empty()!=true)
            {
                curr->right = st.top();
            }
            curr->left = NULL;
        }
        return;
    }

};
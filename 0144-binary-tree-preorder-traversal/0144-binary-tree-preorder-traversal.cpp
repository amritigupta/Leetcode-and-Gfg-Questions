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
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         preorder(root, nodes);
//         return nodes;
//     }
// private:
//     void preorder(TreeNode* root, vector<int>& nodes) {
//         if (!root) {
//             return;
//         }
//         nodes.push_back(root -> val);
//         preorder(root -> left, nodes);
//         preorder(root -> right, nodes);
//     }
    
    
    // ITERATIVE 
//     vector<int> preorderTraversal(TreeNode* root) {
        
//         stack<TreeNode*> st;
//         vector<int> nodes;
//         st.push(root);
        
//         while(!st.empty()){
//             auto it= st.top();
//             st.pop();
//             nodes.push_back(it->val);
            
//             if (it -> right){
//                 st.push(it->right);
//             }
//             if(it->left){
//                 st.push(it->left);
//             }
//         }
        
//         return nodes;
//     }
    
    
    // MORRIS TRAVERSAL
        vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        TreeNode* curr= root;
        while(curr!= NULL)
        {
            if(!curr->left){
                v.push_back(curr->val);
                curr= curr->right;
            }
            else{
                TreeNode* prev= curr->left;
                while(prev->right!=curr && prev->right){
                    prev= prev->right;
                }
                if(prev->right==NULL){
                    prev->right= curr;
                    v.push_back(curr->val);
                    curr= curr->left;
                }
                else{
                    prev->right=NULL;
                    
                    curr= curr->right;
                }
            }
        }
        
        return v;
    }

};
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
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         postorder(root, nodes);
//         return nodes;
        
//     }
    
//     void postorder(TreeNode* root , vector<int> &nodes){
//         if(root==NULL){
//             return ;
//         }
        
//         postorder(root->left, nodes);
//         postorder(root->right, nodes);
//         nodes.push_back(root->val);
//     }
    
    //Iterative using 2 stack
    //  vector<int> postorderTraversal(TreeNode* root) {
    //     vector <int >v;
    //     stack<TreeNode*>st1;
    //     stack<TreeNode*>st2;
    //     st1.push(root);
    //     while(!st1.empty())
    //     {
    //         TreeNode* node =st1.top();
    //         st1.pop();
    //         st2.push(node);
    //         if(node->left!=0) st1.push(node->left);
    //          if(node->right!=0) st1.push(node->right);
    //     }
    //     while(st2.size())
    //     {
    //         v.push_back(st2.top()->val);
    //         st2.pop();
    //     }
    //     return v;
    // }
    
    
    // 1 STACK ITERATIVW
 vector<int> postorderTraversal(TreeNode* root) {
    vector<int> v;
    if (root == NULL) 
        return v; 
  
    // Create two stacks 
    stack<TreeNode *> s1, s2; 
  
    // push root to first stack 
    s1.push(root); 
    TreeNode* node; 
    // Run while first stack is not empty 
    while (!s1.empty()) { 
        // Pop an item from s1 and push it to s2 
        node = s1.top(); 
        s1.pop(); 
        s2.push(node); 
  
        // Push left and right children 
        // of removed item to s1 
        if (node->left) 
            s1.push(node->left); 
        if (node->right) 
            s1.push(node->right); 
    }
    
    while (!s2.empty()) { 
        node = s2.top(); 
        s2.pop(); 
        v.push_back(node->val); 
    } 
    
    return v;   
}

};
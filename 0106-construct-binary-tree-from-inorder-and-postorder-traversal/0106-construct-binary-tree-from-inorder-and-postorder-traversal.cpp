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
    
    // INORDER :  9 3 15 20 7
    // POSTORDER: 9 15 7 20 3
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inmap;
        for(int i=0; i<inorder.size(); i++){
            inmap[inorder[i]]=i;
        }
        
        TreeNode * root = buildtree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inmap);
        
        return root;
    }
    
    TreeNode* buildtree(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, unordered_map<int, int> &inmap){
        
        if (instart>inend || poststart>postend) return NULL;
        
        TreeNode * root = new TreeNode(postorder[postend]);
        
        int inroot = inmap[root->val]; // 3-> 1
        int numsleft = inroot - instart; // 1
        
        root->left = buildtree(inorder, instart, instart+numsleft-1, postorder, poststart, poststart+numsleft-1, inmap);
        root->right= buildtree(inorder, instart+numsleft+1, inend, postorder, poststart+numsleft, postend-1, inmap);
        
        return root;
    }
    
};
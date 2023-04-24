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
    int pow(int x, int y){
        int ans = x;
        for(int i=0; i<y; i++){
            ans=ans*x;
        }
        return ans;
    }
    
    int findheightleft(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node=node->left;
        }
        return h;
    }
    
    int findheightright(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node=node->right;
        }
        return h;
    }    
public:
    int countNodes(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        
        int lh = findheightleft(root->left);
        int rh = findheightright(root->right);
        
        if (lh == rh){
            return pow(2,lh)-1;
        }
        
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
        
    }
};
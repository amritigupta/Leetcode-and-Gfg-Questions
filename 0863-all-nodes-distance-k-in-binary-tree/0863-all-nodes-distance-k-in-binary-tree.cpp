/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void dfs(TreeNode* node, TreeNode* par, unordered_map<TreeNode*, TreeNode*> &mpp){
        mpp[node]=par;
        if(node->left){
            dfs(node->left, node, mpp);
        }
        if(node->right){
            dfs(node->right, node, mpp);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return {};
        unordered_map<TreeNode*, TreeNode*> mpp;
        if(root->left) dfs(root->left, root, mpp );
        if(root->right) dfs(root->right, root, mpp );

        vector<int> ans;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({target, target});

        while(k!=0){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* node = q.front().first;
                TreeNode*  par = q.front().second;
                q.pop();

                if(mpp.find(node)!=mpp.end() && mpp[node]!=par){
                    q.push({mpp[node], node});
                }
                if(node->left && node->left!=par){
                    q.push({node->left, node});
                }
                if(node->right && node->right!=par){
                    q.push({node->right, node});
                }
            }
            k--;
        }

        while(!q.empty()){
            ans.push_back(q.front().first->val);
            q.pop();
        }

        return ans;
    }
};
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
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &track,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                track[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                track[curr->right]=curr;
                q.push(curr->right);
            }
        }


    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*> track;
        markParents(root,track,target);

        unordered_map<TreeNode*,bool> visited;
        vector<int> ans;
        if(!root)return ans;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_level++==k){
                break;
            }

            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(track[curr] && !visited[track[curr]]){
                    q.push(track[curr]);
                    visited[track[curr]]=true;
                }
                

            }
        }
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};
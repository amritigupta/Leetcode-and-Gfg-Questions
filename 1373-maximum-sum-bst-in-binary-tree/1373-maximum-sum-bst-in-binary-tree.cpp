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

int ans;

class prop{
public:
    bool bst;       //to check if tree is bst
    
    int ma;         //max value in a tree
    int mi;         //min value in an tree
    int ms;         //current maximum sum
    
    prop(){
        bst=true;
        ma=INT_MIN;
        mi=INT_MAX;
        ms=0;
    }
    
};

class Solution {
public:
    prop calcSum(TreeNode* root){
        if (root == NULL){
            return prop(); //returns bst = true , minvalue = INTMAX, maxvalue = INTMIN, maxsum = 0
        }
        
        prop p;
        prop pl = calcSum(root->left);                        //recursive call for left sub-tree
        prop pr = calcSum(root->right);                       //recursive call for right sub-tree
		
		//if sub-tree including this node is bst
        
        if ( pl.bst==true && pr.bst==true && root->val>pl.ma && root->val<pr.mi ){
            p.bst = true;   //current tree is a bst
            p.ms = pl.ms + pr.ms + root->val;    //update maxsum       
            p.mi  = min(root->val, pl.mi); //update min 
            p.ma = max(root->val, pr.ma); //update max
        }
        
		//if current tree is not a bst
        else {
            p.bst=false;
            p.ms=max(pl.ms, pr.ms);
        }
		
        ans=max(ans, p.ms);
        return p;
    }
    int maxSumBST(TreeNode* root){
        ans = 0;
        calcSum(root);
        return ans;
    }
};
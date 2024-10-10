/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* createtree(int s, int e, vector<int>&nums){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createtree(s, mid-1, nums);
        root->right = createtree(mid+1, e, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = createtree(0, n-1, nums);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode* temp = head;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        return sortedArrayToBST(nums);
    }
};
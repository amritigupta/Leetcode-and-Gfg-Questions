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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        
        ListNode* curr = head;
        while(curr!=NULL){
            if((curr->next!=NULL) && (curr->val == curr->next->val)){
                ListNode* nextnext=curr->next->next;
                ListNode* delnode= curr->next;
                delete(delnode);
                curr->next = nextnext;
            }
            else{
                curr=curr->next;
            }
            
        }
        return head;  
    }
};
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
    // ITERATIVE
//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = NULL;
//         ListNode* curr = head;   
        
//         while(curr!=NULL){
//             ListNode* forward = curr->next;
//             curr->next = prev;
//             prev=curr;
//             curr=forward;            
//         }
        
//         return prev;
//     }
    
    // recursive
//     void reverse(ListNode* &head, ListNode* &curr, ListNode* &prev){
//         if(curr==NULL){
//             head=prev; //returning new head as prev
//             return;
//         }
        
//         ListNode* forward = curr->next;
//         reverse(head,forward,curr);
        
//         curr->next = prev;  
//     }
    
//     ListNode* reverseList(ListNode* head) {
//         ListNode* curr=head;
//         ListNode* prev = NULL;
//         reverse(head,curr,prev);
//         return head;
//     }
    
     ListNode* reverseList(ListNode* head) {
         if(!head || !head->next){
             return head;
         }
         
         ListNode* chotahead= reverseList(head->next);
         
         head->next->next = head;
         head->next = NULL;
         
         return chotahead;
     }
};
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
    ListNode* reverse(ListNode* head)
    {
       ListNode* cur = head;
       ListNode* prev = NULL;
       ListNode* next = NULL;
        
       while(cur!=NULL)
       {
           next = cur->next;
           cur->next = prev;
           prev = cur;
           cur = next;

       }
        head = prev;
        return head;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* rev = reverse(slow->next);  
        ListNode* cur = head;  
        
        while(rev!=NULL) //after reversing the second part we compare all the elements
        {
            if(rev->val!=cur->val) 
            {
             return false;   
                
            }           
            rev = rev->next;
            cur = cur->next;
            
        }
        
        return true;
    }
};
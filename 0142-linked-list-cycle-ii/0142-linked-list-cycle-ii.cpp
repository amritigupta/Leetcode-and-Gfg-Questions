/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {

public:
ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    
    ListNode *slow  = head;
    ListNode *fast  = head;
    ListNode *entry = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {                      // there is a cycle
            while(slow != entry) {               // found the entry location
                slow  = slow->next;
                entry = entry->next;
            }
            
            return entry; //returns loop start point
        }
        
    }
    return NULL;                                 // there has no cycle
}

    /*
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        map<ListNode*, bool> vis;
        ListNode* temp = head;
        while(temp!=NULL){
            if(vis[temp]==true){
                return temp;
            }
            
            vis[temp]=true;
            temp=temp->next;
        }
        
        return NULL;        
    }
    */
};

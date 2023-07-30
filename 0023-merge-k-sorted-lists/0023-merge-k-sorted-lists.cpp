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
// class Solution {

// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         int k = lists.size(); 
//         if(k == 0) // if size is zero
//             return NULL; 
        
//         // making a vector pair where first contain value and second contain node
//         vector<pair<int, ListNode*>> arr; 
        
//         for(int i = 0; i < k; i++)
//         {
//             ListNode* curr_list = lists[i];
            
//             while(curr_list != NULL)
//             {
//                 arr.push_back({curr_list -> val, curr_list});
//                 curr_list = curr_list -> next;
//             }
//         }
        
       
//         // suppose an array like this [[],[],[],]
//         if(arr.size() == 0)
//             return NULL;
        
//         sort(arr.begin(), arr.end()); 
          
//         // start making links b/w the elements of vector
//         for(int i = 0; i < arr.size() - 1; i++)
//         {
//             arr[i].second -> next = arr[i + 1].second;
//         }
        
//         // in the next of last node put NULL
//         arr[arr.size() - 1].second -> next = NULL;
        
//         return arr[0].second; // return first node of the vector
//     }
// };

class comparator{
    public:
    bool operator()(ListNode *x,ListNode *y){
        return (x->val>y->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comparator> pq; //minheap
        
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                pq.push(lists[i]);
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *tail=dummy;
        
        while(!pq.empty()){
            ListNode *top=pq.top();
            pq.pop();
            tail->next=top;
            tail=tail->next;
            if(top->next)
                pq.push(top->next);
        }   
        return dummy->next;
    }
};
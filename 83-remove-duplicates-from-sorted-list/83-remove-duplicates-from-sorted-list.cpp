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
        
        if(!head || !head->next)
            return head;
        
        ListNode* front = head;
        
        while(front && front->next){
            
            if(front->val == front->next->val){
                front->next = front->next->next;
            }
            else{
                front=front->next;
            }
        }
        
       
        return head;
    }
};
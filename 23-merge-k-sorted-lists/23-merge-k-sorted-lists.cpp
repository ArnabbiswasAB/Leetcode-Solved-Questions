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
    ListNode* merge(ListNode* list1 , ListNode* list2){
     
        if(!list1 && !list2)
            return list1;
        
        if(!list1)
            return list2;
        else if(!list2)
            return list1;
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while(list1 && list2){
            
            if(list1->val <= list2->val){
                curr->next = list1;
                list1=list1->next;
            }
            else{
                curr->next = list2;
                list2=list2->next;
            }
            curr = curr->next;
        }
        
        if(list1){
            curr->next = list1;
        }
        else
            curr->next = list2;
        
        return dummy->next;
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* merged = NULL;
        for(int i=0; i<lists.size(); i++){
            
            merged = merge(lists[i],merged);
        }
        
        return merged;
    }
};
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* tail2 = list2;
        while(tail2->next)
            tail2=tail2->next;
        
        ListNode* mid1 = list1, *mid2=list1;
        for(int i=1; i<a; i++)
            mid1=mid1->next;
        
        for(int i=0; i<b; i++)
            mid2=mid2->next;
        
        mid1->next=list2;
        tail2->next=mid2->next;
        
        return list1;
    }
};
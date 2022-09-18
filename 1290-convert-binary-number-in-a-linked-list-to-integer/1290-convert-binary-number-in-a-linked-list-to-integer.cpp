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
    
    int countBinary(ListNode* head, int &sum){
     
        if(!head)
            return 0;
        
        int data = countBinary(head->next, sum);
        sum += (pow(2,data)*head->val) ;
        cout<<sum;
        return data + 1;
    }
    
    
    int getDecimalValue(ListNode* head) {
        
        if(!head)
            return 0;
        
        int sum = 0;
       countBinary(head, sum);
        return sum;
    }
};
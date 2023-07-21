//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends


class Solution
{
    public:
    int findLen(node* head){
      
      if(!head)
      return 0;
      
      return 1 + findLen(head->next);
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        
        if(!head || !head->next || k == 0)
        return head;
        
        node* dummy = new node(0);
        dummy->next = head;
        
        node* prev = dummy, *next = dummy, *curr = dummy;
        int length = findLen(head);
        
        while(length>0){
            
            curr = prev->next;
            next = curr->next;
            
            int toLoop = length>k?k:length;
            
            for(int i=1; i<toLoop; i++){
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                
                next = curr->next;
            }
            
            length -= toLoop;
            prev = curr;
        }
      
      return dummy->next;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends
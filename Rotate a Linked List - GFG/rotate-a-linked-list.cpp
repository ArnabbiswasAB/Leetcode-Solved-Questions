//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends


class Solution
{
    public:
    //Function to rotate a linked list.
    int findLen(Node* head){
        
        if(!head)
        return 0;
        
        return 1 + findLen(head->next);
    }
    
    Node* rotate(Node* head, int k)
    {
           
        if(!head || !head->next || k == 0)
        return head;
        
        int length = findLen(head);
        
        Node* tail = head;
        while(tail->next)
        tail = tail->next;
        
        tail->next = head;
        
        while(tail && k--){
            tail = tail->next;
        }
        
        head = tail->next;
        tail->next = NULL;
        
        return head;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends
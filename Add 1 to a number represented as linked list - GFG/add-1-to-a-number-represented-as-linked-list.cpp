//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    int helper(Node* head){
        
        if(!head)
        return 1;
        
        int sum = head->data + helper(head->next);
        head->data = sum % 10;
        
        return sum/10;
    }
    
    Node* addOne(Node *head) 
    {
       
       if(!head){
           return new Node(1);
       }
       
       int carry = helper(head);
       if(carry != 0)
       {
           Node* node = new Node(carry);
           node->next = head;
           return node;
       }
       
       return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
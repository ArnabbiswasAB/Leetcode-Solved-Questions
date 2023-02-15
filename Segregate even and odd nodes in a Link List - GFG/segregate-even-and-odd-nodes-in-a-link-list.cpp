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
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        
        struct Node *oddD= new Node(0);
        struct Node *evenD= new Node(0);
        struct Node *odd=oddD;
        struct Node *even=evenD;
        struct Node *curr=head;
        while(curr){
            if((curr->data)%2==0){
                even->next=curr;
                even=even->next;
                curr=curr->next;
            }
            else{
                odd->next=curr;
                odd=odd->next;
                curr=curr->next;
            }
        }
        
        if(evenD->next==NULL){
            return (head=oddD->next);
        }
        else if(oddD->next==NULL){
            return (head=evenD->next);
        }
        
        head=evenD->next;
        even->next=oddD->next;
        odd->next=NULL;
        return head;
        
        
    
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends
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


class Solution{
public:
    Node* divide(int N, Node *head){
       
       if(!head || !head->next)
       return head;
       
       Node* oddH = new Node(0), *evenH = new Node(0);
       Node* odd = oddH, *even = evenH, *curr = head;
       
       while(curr){
         
         if(curr->data % 2 == 0){
             even->next = curr;
             even = even->next;
         }else{
             odd->next = curr;
             odd = odd->next;
         }   
         
         curr = curr->next;
       }
       
       even->next = oddH->next;
       odd->next = NULL;
       return evenH->next;
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
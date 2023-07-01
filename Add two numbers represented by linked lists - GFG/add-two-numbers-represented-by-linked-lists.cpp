//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends


class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* addDigits(Node* first, Node* second, int &carry){
        
        if(!first && !second)
        return NULL;
        
        Node* newNode = new Node(-1);
        newNode->next = addDigits(first->next, second->next, carry);
        
        newNode->data = (first->data + second->data + carry)%10;
        carry = (first->data + second->data + carry)/10;
        
        return newNode;
    }
    
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        
        Node* ptr1 = first, *ptr2 = second;
        
        while(ptr1 || ptr2){
            
            if(ptr1 == NULL){
                Node* newNode = new Node(0);
                newNode->next = first;
                first = newNode;
                
                ptr2 = ptr2->next;
            }else if(ptr2 == NULL){
                Node* newNode = new Node(0);
                newNode->next = second;
                second = newNode;
                
                ptr1 = ptr1->next;
            }else{
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        
        Node* dummy = new Node(-1);
        int carry = 0;
        
        dummy->next = addDigits(first, second, carry);
        
        if(carry != 0){
            Node* newNode = new Node(carry);
            newNode->next = dummy->next;
            dummy->next = newNode;
        }
        
        return dummy->next;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
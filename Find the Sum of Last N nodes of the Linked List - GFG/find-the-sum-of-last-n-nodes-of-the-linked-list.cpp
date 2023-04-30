//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
};

void append(struct Node** headRef, int newData)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node *last = *headRef;
	new_node->data = newData;
	new_node->next = NULL;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

int sumOfLastN_Nodes(struct Node* head, int n);

// Driver program to test above
int main()
{
    int t;
    cin>>t;
    while(t--){
        struct Node* head = NULL;
        int n,m,tmp;
        cin>>m>>n;
        while(m--){
            cin>>tmp;
            append(&head, tmp);
        }
        cout<<sumOfLastN_Nodes(head, n)<<endl;
    }
	return 0;
}

// } Driver Code Ends


int sumOfLastN_Nodes(struct Node* head, int n)
{
      // Code here
      if(n == 0 || !head)
      return 0;
      
      int len = 0;
      Node* curr = head;
      
      while(curr){
          len++;
          curr = curr->next;
      }
      
      curr = head;
      
      int i=0;
      while(i<len-n && curr){
      curr = curr->next;
      i++;
     }
     
     int sum = 0;
     while(curr){
         sum += curr->data;
         curr = curr->next;
     }
     
     return sum;
}
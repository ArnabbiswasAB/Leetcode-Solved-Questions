//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
        if(!head || !head->next)
        return head;
        
        Node* dummy = new Node(0);
        dummy->next = head;
        
        Node* outer = head;
        
        while(outer && outer->next){
            
            Node* inner = dummy, *prev = NULL;
            
            while(inner != outer){
                
                if(inner->next->data > outer->next->data){
                    prev = inner->next;
                    inner->next = outer->next;
                    outer->next = outer->next->next;
                    inner->next->next = prev;
                    break;
                }
                
                inner = inner->next;
            }
            
            if(inner == outer)
            outer = outer->next;
        }
        
        return dummy->next;
    }
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends
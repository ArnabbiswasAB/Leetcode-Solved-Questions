//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{

    public:
    
    class Node{
        public :
        int val, key;
        Node* next, *prev;
        
        Node(int _key, int _val){
            val = _val;
            key = _key;
        }
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>mp;
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity)
    {
        // code here
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* res){
        Node* temp = head->next;
        
        res->next = temp;
        temp->prev = res;
        
        head->next = res;
        res->prev = head;
    }
    
    void deleteNode(Node* res){
        
        Node* delprev = res->prev;
        Node* delnext = res->next;
        
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mp.find(key) != mp.end()){
            Node* res = mp[key];
            int ans = res->val;
            mp.erase(res->key);
            deleteNode(res);
            addNode(res);
            
            mp[key] = head->next; 
            return ans;
        }
        
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here   
        if(mp.find(key) != mp.end()){
            Node* res = mp[key];
            deleteNode(res);
            mp.erase(key);
        }
        
        if(mp.size() == cap){
            Node* res = tail->prev;
             mp.erase(res->key);
            deleteNode(res);
           
        }
        
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
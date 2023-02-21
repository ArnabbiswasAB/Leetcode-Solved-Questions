//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


//reverse all of queue
void recursion_1(queue<int>&q){
    if(q.empty()) return;
    
    int front = q.front();
    q.pop();
    recursion_1(q);
    q.push(front);
}

//reverse first k and append to the end
void recursion_2(queue<int>&q, int k){
    if(q.empty() or k==0) return;
    
    int front = q.front();
    q.pop();
    recursion_2(q, k-1);
    q.push(front);
}

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    recursion_1(q);
    recursion_2(q, q.size() - k);
    return q;
}

// Expected Time Complexity : O(N)
// Expected Auxiliary Space : O(K)
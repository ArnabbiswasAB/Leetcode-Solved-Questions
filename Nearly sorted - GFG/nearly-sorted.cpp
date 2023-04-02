//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
   
     vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        vector <int> res;
        //implementing MinHeap using priority queue and 
        //storing first k elements in it.
        priority_queue<int, vector<int>, greater<int>> pq(arr, arr+K + 1); 
	
	    for(int i = K + 1; i<num; ++i)
	    {
	        //storing top element from priority queue in list and popping it.
	        res.push_back (pq.top ());
	        pq.pop();
	        
	        //pushing the current array element in priority queue.
	        pq.push(arr[i]);
	    }
	    
	    //using a loop till priority queue becomes empty.
	    while(!pq.empty())
	    {
	        //storing top element from priority queue in list and popping it.
	        res.push_back (pq.top ());
	        pq.pop();
	    }
	    //returning the list.
	    return res;
        
    }
   
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends
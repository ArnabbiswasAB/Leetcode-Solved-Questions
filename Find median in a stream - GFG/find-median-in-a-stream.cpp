//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int>small;
    priority_queue<int, vector<int>, greater<int>> large;
    
    void insertHeap(int &x)
    {
        
        small.push(x);
        
        if(!small.empty() && !large.empty() && small.top() > large.top())
        {
            int val = small.top();
            small.pop();
            
            large.push(val);
        }
        
        
        if(small.size() > large.size() + 1){
            
            int val = small.top();
            small.pop();
            
            large.push(val);
        }
        else if(large.size() > small.size() + 1){
             int val = large.top();
            large.pop();
            
            small.push(val);
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        
        if(small.size() == large.size()){
            return ((double)small.top() + (double)large.top())/2;
        }
          else if(small.size() == large.size() + 1)
        {
            return double(small.top());
        }
        
        else
        {
            return double(large.top());
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends
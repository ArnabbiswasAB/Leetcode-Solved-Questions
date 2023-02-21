//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        
        long long area = 0;
        stack<long long>st;
        
        for(int i=0; i<=n; i++){
            
            while(!st.empty() && (i == n || arr[st.top()] >= arr[i])){
                
                long long height = arr[st.top()];
                st.pop();
                
                long long width = 0;
                
                if(st.empty())
                width = i;
                else{
                    width = i - st.top() - 1;
                }
                
                area = max(area, height * width);
            }
            
            st.push(i);
        }
        
        return area;
        
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  bool res = false;
  
    void helper(int a[],int n,int k,int curr,int i,int sum, vector<int>& vis){
        
        if(i == n || curr > sum){
            return ;
        }
        
        if(k == 1){
            res = true;
            return;
        }
        
        if(curr == sum){
            return helper(a, n, k-1, 0, 0, sum, vis);
        }
     
            
            if(!vis[i]){
                vis[i] = 1;
                helper(a, n, k, curr + a[i], i+1, sum, vis);
                vis[i] = 0;
            }
        
        helper(a, n, k, curr, i+1, sum ,vis);
    }
    
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum = 0;
         for(int i=0; i<n; i++){
             sum += a[i];
         }
         
         res = false;
         if(sum % k != 0)
         return false;
         
         vector<int>vis(n,0);
         helper(a, n, k, 0, 0, sum/k, vis);
         return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends
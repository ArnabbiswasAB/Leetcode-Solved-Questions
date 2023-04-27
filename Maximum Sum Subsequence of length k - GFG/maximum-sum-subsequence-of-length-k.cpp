//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	int solve(vector<int>&a,int k,int i,int prev){

         if(k<0)

             return INT_MIN;

         if(i>=a.size()){

             if(k==0)

                 return 0;

             return INT_MIN;

         }

         int ans=INT_MIN;

         if(prev==-1){

             int temp1=a[i]+solve(a,k-1,i+1,i);

             int temp2=solve(a,k,i+1,prev);

             ans=max({ans,temp1,temp2});

         }

         else{

             if(a[prev]<=a[i] && k>0){

                 int temp1=a[i]+solve(a,k-1,i+1,i);

                 int temp2=solve(a,k,i+1,prev);

                 ans=max({ans,temp1,temp2});

             }

             else

                 ans=max(ans,solve(a,k,i+1,prev));

         }

         return ans;

     }

 int max_sum(vector<int> &a, int k){

     return solve(a,k,0,-1)<0?-1:solve(a,k,0,-1);

 }
 
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n, k;
    	cin >> n >> k;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin >> v[i];
        Solution ob;
        cout<<ob.max_sum(v, k)<<"\n";
     }
	return 0;
}


// } Driver Code Ends
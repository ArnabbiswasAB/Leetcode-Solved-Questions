//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       
       vector<int>ans(n,0);
       stack<pair<int,int>>st;
       
       for(int i=0; i<n; i++){
           
           if(st.empty()){
               ans[i] = 1;
               st.push({price[i],1});
               continue;
           }
           
           int val = 1;
           while(!st.empty() && price[i] >= st.top().first){
               val += st.top().second;
               st.pop();
           }
           
           ans[i] = val;
           st.push({price[i], val});
       }
       
       return ans;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends
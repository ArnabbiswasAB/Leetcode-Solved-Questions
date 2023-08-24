//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int N)
{
   
   int binary[32] = {0};
   int ans = 0, i=0;
        
   while(N){
      
      binary[i] = N%2;
      i++;
      N /= 2;
   }   
   
   for(int ind=i-1; ind>=0; ind--)
     cout<<binary[ind];
     
   return;     
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    	string MaxZero(string a[],int n)
    	{
    	    
    	    int ans = -1;
        string num = "-1";
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(auto j:a[i])
                cnt += (j == '0');
                
            if(cnt > ans){
                ans = cnt;
                num = a[i];
            }
            if(cnt == ans){
                if(a[i].size() > num.size())
                    num = a[i];
                else if(a[i].size() == num.size() && a[i]>num)
                    num = a[i];
            }
        }
        return ans == 0 ? "-1" : num ;
    }
};
	 

//{ Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    string a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    

      

        Solution ob;
        cout << ob.MaxZero(a,n) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
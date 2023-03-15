//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	vector<int> findKmp(string p){
	    
	    int n = p.length();
	    vector<int> kmp(n,0);
	    
	    int i=1,j=0;
	    
	    while(i<n){
	        
	        if(p[i] == p[j]){
	            kmp[i] = j+1;
	            j++;
	            i++;
	        }else{
	            if(j!=0)
	              j = kmp[j-1];
	              else{
	                  kmp[i] = 0;
	                  i++;
	              }
	        }
	    }
	    
	    return kmp;
	}
	
	
	int search(string s, string p)
	{
	    // Your code goes here
	    int i=0, j=0, n=s.length(), m=p.length();
      
      vector<int>kmp = findKmp(p);

      while(i<n){
        
        if(s[i] == p[j]){
            i++;
            j++;
        }

        if(j>=m){
            return 1;
        }
        else if(i<n && s[i] != p[j]){
            if(j!=0){
                j = kmp[j-1];
            }else{
                i++;
            }
        }
      }

      return 0;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string x, y;
   		cin >> x >> y;



        Solution ob;
   		cout << ob.search(x, y) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    
	      int odd=0;
    int even=0;
      
      for(int i=0;i<s.length();i++)
      {
          int bit= s[i] - '0';
          
          if(i%2==0)
              even+=bit;
          else
              odd+=bit;
          
      }
      int ans = abs(even-odd);
      ans =ans%3==0?1:0;
      return ans;
      
	}
};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends
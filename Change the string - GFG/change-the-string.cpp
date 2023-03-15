//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    
    string modify (string s)
    {
        // your code here
        int flag = 0;
        
        if(s[0]>=65 && s[0] <= 90)
          flag -= 32;
        else
          flag += 32;
          
          
          for(int i=1; i<s.length(); i++){
               
               if(flag < 0){
                   if(s[i] >= 97)
                     s[i] += flag;
               }
               else{
                   if(s[i] <= 90)
                     s[i] += flag;
               }
          }
          
          return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.modify (s) << endl;
	}
}
// } Driver Code Ends
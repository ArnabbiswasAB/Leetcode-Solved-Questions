//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool metaStrings (string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << metaStrings (s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


bool metaStrings (string s1, string s2)
{
    // your code here
    
    int i=0, j=0, n = s1.length(), m = s2.length();
    
    if(n != m || s1 == s2)
    return false;
    
   int first = -1, second = -1;
   for(i=0; i<n; i++){
       
       if(s1[i] == s2[i]){
           continue;
       }
       else{
           
           if(first == -1)
            first = i;
           else
           break;
       }
   }
   
   swap(s1[i],s1[first]);
   
   return s1 == s2;
}
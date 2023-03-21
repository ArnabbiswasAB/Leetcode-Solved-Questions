//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    // Your code goes here
	    
	    int N = s.length();
        
        // preprocess s for longest proper prefix same as suffix
        vector<int>lps(N);
        
        int i = 1;
        int j = 0;
        lps[0] = 0;
        
        while(i<N)
        {
            if(s[i]==s[j])
            {
                lps[i] = j+1;
                i++;
                j++;
            }
            else
            {
                if(j==0)
                {
                    lps[i] = 0;
                    i++;
                    continue;
                }
                else
                {
                    j = lps[j-1];                    
                }
            }
        }
        
        // X times repeating substring with length K will have N-K value at lps[sl-1]
        // so we varify if lps[sl-1] is divisible by K which is (N-lps[sl-1])
        // which means checking if N-K == (X-1) * K
        return lps[N-1] && (lps[N-1]%(N-lps[N-1])==0);
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
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
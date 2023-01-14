//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int count1=0 , count0 =0;
        int zero=0;
        
        for(int i=0; i<str.size(); i++){
            
            if(str[i] == '0'){
                count0++;
            }
            else {
                count1++;
            }
            
            if(count1 == count0)
            zero++;
        }
        
        if(count0 != count1)
        return -1;
        
        return zero;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
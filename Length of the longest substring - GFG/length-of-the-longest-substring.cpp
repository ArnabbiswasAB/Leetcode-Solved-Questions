//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
    
        vector<int>uni(256,-1); //string can have only 256 diff characters at a time
       int i=0,j=0,n=s.size();
        
        if(n==0) return 0;  // 0 characters present
        
        int len=0,maxlen=0;
        while(j<n ){
            
            if(uni[s[j]]!=-1){          //if element is present already
                i=max(uni[s[j]]+1,i);
                
            }
            uni[s[j]]=j;                //if element is not present
            len=j-i+1;
            maxlen=max(len,maxlen);
            j++;                //moving right
            
            
        }
        
        return maxlen;
        /*
        int n = s.length();
		int j=0,mx=0;
		unordered_map<char,int> mp;
		for(int i=0;i<n;i++) {
			mp[s[i]]++;
			while(mp[s[i]]>1) {
				mp[s[j]]--;
				j++;
			}
			mx=max(mx,i-j+1);
		}
		return mx;
        */
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
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends
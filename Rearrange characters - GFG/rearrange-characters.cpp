//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends

   class Solution
{
    public:
    string rearrangeString(string str)
    {
       
       unordered_map<char,int>mp;
       for(int i=0; i<str.length(); i++)
         mp[str[i]]++;
       
       
       priority_queue<pair<int,char>>pq;
       for(auto it : mp){
           pq.push({it.second, it.first});
       }
       
       string ans = "";
       
        if(pq.size() == 1) return "-1";
        
       while(pq.size() > 1){
           
           auto it1 = pq.top();
           pq.pop();
           auto it2 = pq.top();
           pq.pop();
           
           ans += it1.second;
           ans += it2.second;
           
          if(it1.first > 1) pq.push({it1.first-1,it1.second});
            if(it2.first > 1) pq.push({it2.first-1,it2.second});
       }
       
       
       if(pq.size() == 1  and pq.top().first == 1)
            ans+=pq.top().second;
        if(pq.size() == 1 and pq.top().first > 1) return "-1";
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
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string s)
    {
        // Your code goes here 
        
       int len1 = s.length();
        string t = "";
        
        set<char> st;
        for (int i = 0; i < len1; i++) 
            st.insert(s[i]);
        for (auto i = st.begin(); i != st.end(); i++) 
            t += (*i);
                
        int len2 = t.length();
    
        // check if string's length is less than pattern's
        // length. If yes then no such window can exist
        if (len1 < len2) {
            return 0;
        }
    
       unordered_map<char,int>mp;
       
    int minlen=INT_MAX, end=0, start=0, size = s.size(),minstart=0;
        
        for(int i=0; i<t.size(); i++)
        mp[t[i]]++;
        
        int counter=t.size();
        
        while(end<size){
            
            if(mp[s[end]] > 0)
               counter--;
               
            mp[s[end]]--;
            end++;
            
            while(counter == 0){
                
                if(end - start < minlen){
                    minstart=start;
                    minlen = end - start;
                }
                
                mp[s[start]]++;
                
                if(mp[s[start]] > 0)
                counter++;
                
                start++;
            }
        }
        
        if(minlen != INT_MAX)
        return s.substr(minstart, minlen).size();
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends
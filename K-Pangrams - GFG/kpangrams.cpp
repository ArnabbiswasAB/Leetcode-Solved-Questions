//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool kPangram(string str, int k);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin.ignore();
        string str;
        getline(cin,str);
        int k;
        cin>>k;
        cout<<kPangram(str,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool kPangram(string s, int k)
{
    // code here 
    
    vector<int>freq(26,0);
    int count = 0, unique = 0;
    
    for(int i=0; i<s.length(); i++){
        
        if(s[i] == ' ')
        continue;
        
        if(freq[s[i] - 'a'] == 0)
        unique++;
        
        count++;
        freq[s[i] - 'a']++;
    }
    
    if(count < 26)
    return false;
    
    return 26 - unique <= k; 
}
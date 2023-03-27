//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{

    public:
    
   bool isThere(string &text,string &pat,vector<int>&lps) {
    int i=0,j=0;
    // i for text
    // j for pat
    while(i<text.length()) {
        if(text[i]==pat[j]) {
            i++;
            j++;
        }
        if(j==pat.length()) {
            return true;
        }
        else if(j<pat.length() && pat[j]!=text[i]) {
            if(j==0) {
                i++;
            }
            else {
                j=lps[j-1];
            }
        }
    }
    return false;
}
vector<int>lpsConstructor(string &pat) {
    vector<int>lps(pat.length());
    int i=1,j=0;
    while(i<pat.length()) {
        if(pat[i]==pat[j]) {
            lps[i++]=(j++)+1;
        }
        else {
            if(j==0) {
                lps[i++]=0;
            }
            else {
                j=lps[j-1];
            }
        }
    }
    return lps;
}
int repeatedStringMatch(string a, string b) {
    int steps=1;
    string s=a;
    while(a.length()<b.length()) {
        a+=s;
        steps++;
    }
    vector<int>lps=lpsConstructor(b);
    if(isThere(a,b,lps)) {
        return steps;
    }
    a+=s;
    if(isThere(a,b,lps)) {
        return steps+1;
    }
    return -1;
}
  
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution obj;
        cout<<obj.repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}

// } Driver Code Ends
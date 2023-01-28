//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
  vector<string>ans;
  unordered_map<string,int>mp;
  
  int getInvalid(string s){
       stack<char>st;
       
       for(int i=0; i<s.size(); i++){
           
           if(s[i] == '(')
           st.push('(');
           else if(s[i] == ')'){
               if(!st.empty() && st.top() == '(')
               st.pop();
               else
               st.push(')');
           }
       }
       
       return st.size();
  }
  
  
  void helper(string s,int invalid){
      
      if(mp[s] != 0)
      return ;
      else
      mp[s]++;
      
      if(invalid < 0)
      return;
      
      if(invalid == 0){
          if(getInvalid(s) == 0)
             ans.push_back(s);
             
        return;     
      }
      
      
      for(int i=0; i<s.size(); i++){
          
          string left = s.substr(0,i);
          string right = s.substr(i+1);
          
          helper(left + right, invalid - 1);
      }
      
      return ;
  }
  
    vector<string> removeInvalidParentheses(string s) {
        // code here
       
        helper(s, getInvalid(s));
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends
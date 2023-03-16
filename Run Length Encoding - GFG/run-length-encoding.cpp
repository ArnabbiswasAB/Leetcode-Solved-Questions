//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{     
  //Your code here 
  
  string ans = "";
  int count = 1;
  s += '$';
  
  for(int i=0; i<s.length()-1; i++){
      
      if(s[i] == s[i+1]){
          count++;
      }else{
          ans += s[i];
          ans += to_string(count);
          count = 1;
      }
  }
  
  return ans;
}     
 

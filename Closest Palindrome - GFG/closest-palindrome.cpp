//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int closestPalindrome(long long int num){
	   
	   string s = to_string(num);
	   int n =  s.length();
	   if(n == 1)
	   return num;
	   
	   
	   vector<long long int>cand;
	   
	   cand.push_back(pow(10,n) + 1);
	   cand.push_back(pow(10,n-1) -1);
	   
	   int mid = (n+1)/2;
	   long prefix = stol(s.substr(0,mid));
	   
	   vector<long long int> v = {prefix, prefix - 1, prefix + 1};
	   
	   for(auto it : v){
	       string postfix = to_string(it);
	       if(n%2 != 0)
	       postfix.pop_back();
	       
	       reverse(postfix.begin(),postfix.end());
	       string c = to_string(it) + postfix;
	       cand.push_back(stol(c));
	   }
	   
	   long long int result , minDiff = LONG_MAX, num1 = num;
	   
	   for(int i=0; i<5; i++){
	       
	       if(abs(cand[i] - num1) < minDiff){
	           result = cand[i];
	           minDiff = abs(cand[i] - num1);
	       }
	       else if(abs(cand[i] - num1) == minDiff){
	           result = min(result, cand[i]);
	       }
	   }
	   
	   return result;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
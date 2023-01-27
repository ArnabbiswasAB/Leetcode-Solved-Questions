//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int shortestDistance(vector<string> &s, string word1, string word2)
	{
		// Your code goes here
		unordered_map<string, vector<int>>mp;
		
		for(int i=0; i<s.size(); i++){
		    
		    if(s[i] == word1){
		        mp[word1].push_back(i);
		    }
		    else if(s[i] == word2){
		        mp[word2].push_back(i);
		    }
		}
		
		int ans = INT_MAX;
		vector<int> first = mp[word1];
		vector<int> second = mp[word2];
		int i=0, j=0;
		
		while(i<first.size() && j<second.size()){
		    
		    ans = min(ans, abs(first[i] - second[j]));
		    
		    if(first[i] < second[j]){
		        i++;
		    }
		    else{
		        j++;
		    }
		}
		
		
		return ans;
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
   		int n;
   		cin >> n;

   		vector<string> s(n);
   		for(int i = 0; i < n; i++)
   			cin >> s[i];

   		string word1, word2;

   		cin >> word1 >> word2;
   		
   		Solution ob;

   		cout << ob.shortestDistance(s, word1, word2) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
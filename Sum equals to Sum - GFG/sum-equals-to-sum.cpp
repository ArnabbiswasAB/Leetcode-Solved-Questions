//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int findPairs(long long a[], long long n)
    {
        //code here.
        
         unordered_map<int,int>mp;
        for(int i=0;i<n-1;++i) {
            for(int j=i+1;j<n;++j) {
                int sum = a[i] + a[j];
                if(mp.find(sum) == mp.end()) {
                    mp[sum]++;
                }
                else {
                    return 1;
                }
            }
        }
        return 0;
    }
    
    /*
    Time Complexity :- O(n^2)
    Space Complexity :- O(n^2)
    */
    
};

//{ Driver Code Starts.
int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }
	    Solution ob;
	    cout << ob.findPairs(a, n) << endl;   
	    }
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:

	vector<int> row{0,0,1,-1,0};
	vector<int> col{1,-1,0,0,0};
	
	long long solve(vector<vector<int>>& keypad, int i, int j, int n, vector<vector<long long>>& memo){
	    if(i<0 or i>=4 or j<0 or j>=3 or keypad[i][j]==-1){
	        return 0;
	    }
	    if(n == 1){
	        return 1;
	    }
	    if(memo[keypad[i][j]][n] != -1){
	        return memo[keypad[i][j]][n];
	    }
	    
	 //   memo[keypad[i][j]][n] = solve(keypad, i, j, n-1, memo);
	    long long ans = 0;
	    
	    for(int k=0; k<5; k++){
	        int ni = i+row[k];
	        int nj = j+col[k];
	        
	        ans += solve(keypad, ni, nj, n-1, memo);
	    }
	    
	    return memo[keypad[i][j]][n] = ans;
	}
	
	
	long long getCount(int N)
	{
	    vector<vector<int>> keypad{{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
	    vector<vector<long long>> memo(10, vector<long long>(N+1, -1));
	   
	    long long result = 0;
	    
	    for(int i=0; i<4; i++){
	        for(int j=0; j<3; j++){
	            result += solve(keypad, i, j, N, memo);
	        }
	    }
	    
	    return result;
	}

};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
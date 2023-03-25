//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<vector<int>> ans;
	
	void helper(int ind, int target, vector<int>& temp){
	    
	    if(target == 0){
	        ans.push_back(temp);
	        return;
	    }
	    
	    for(int i = ind; i>=1; i--){
	        
	        if(target - i >=0){
	            temp.push_back(i);
	            helper(i, target - i, temp);
	            temp.pop_back();
	        }
	    }
	}
	
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        
        vector<int>temp;
        helper(n,n,temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends
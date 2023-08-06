//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& nums) {
         
         sort(nums.begin(),nums.end());
         vector<int> temp = nums[0];
         vector<vector<int>> ans;
         
         for(int i=1; i<nums.size(); i++){
             
             if(nums[i][0] <= temp[1]){
                 temp[1] = max(temp[1],nums[i][1]);
             }else{
                 ans.push_back(temp);
                 temp = nums[i];
             }
         }
         
         ans.push_back(temp);
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
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
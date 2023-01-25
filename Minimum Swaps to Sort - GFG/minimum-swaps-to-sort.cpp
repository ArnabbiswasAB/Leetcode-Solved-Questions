//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    unordered_map<int,int> mp;

     int n = nums.size();

     for(int i = 0; i<n; i++)

     {

         mp[nums[i]] = i;

     }

     

     sort(nums.begin(),nums.end());

     

     

     int i = 0;

     int steps = 0;

     while (i<nums.size())

     {

         if (nums[i] == nums[mp[nums[i]]])

         {

             i += 1;

         }

         else

         {

             swap(nums[i],nums[mp[nums[i]]]);

             steps += 1;

         }

     }

     return steps;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
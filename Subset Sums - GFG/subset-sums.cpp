//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void helper(vector<int> num, int i, int n, vector<int>& ans, int sum){
     
     if(i == n){
       ans.push_back(sum);
       return;
     }

     helper(num, i+1, n, ans, sum + num[i]);
     helper(num, i+1, n, ans, sum);
}


    vector<int> subsetSums(vector<int> nums, int N)
    {
        // Write Your Code here
        
         int i=0, n=nums.size();
     vector<int>ans;
     
     helper(nums, i, n, ans, 0);
     return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
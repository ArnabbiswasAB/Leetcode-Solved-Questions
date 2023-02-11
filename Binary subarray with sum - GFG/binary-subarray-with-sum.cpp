//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        // code here
        
        unordered_map<int,int>mp;
        mp[0] = 1;
        int i = 0, ans = 0, sum = 0;
        
        while(i<N){
            
            sum += arr[i];
            
            if(mp.find(sum - target) != mp.end())
            ans += mp[sum - target];
            
            mp[sum]++;
            i++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends
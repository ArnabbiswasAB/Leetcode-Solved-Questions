//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int nums[], int n)
    {
        //code here.
        
        int low = 0, high = n-1;
        
        while(low<=high){
            
            int mid = low + (high - low)/2;
            int left = mid - 1;
            int right = mid + 1;
            
            bool Index = (mid % 2 == 0)?1:0;
            
            if(left>=0 && nums[mid] == nums[left]){
                
                if(Index){
                    high = left - 1;
                }
                else{
                    low = right;
                }
            }
            else if(right < n && nums[right] == nums[mid]){
                
                if(Index){
                    low = right + 1;
                }
                else{
                    high = left;
                }
            }
            else{
                return nums[mid];
            }
        }
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
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends
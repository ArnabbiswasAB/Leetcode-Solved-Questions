//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here 
            
            sort(arr, arr + n);
            int i=0, j=n-1, ans = 0, minDiff = INT_MAX;
            
           while(i<j){
               
               int sum = arr[i] + arr[j];
               
               if(sum == 0)
               return 0;
               
               if(abs(sum) < minDiff){
                   minDiff = abs(sum);
                   ans = sum;
               }
               else if(abs(sum) == minDiff){
                   ans = max(ans,sum);
               }
               
               if(sum < 0)
                i++;
                else
                j--;
           }
           
           return ans;
        }
};

//{ Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}
// } Driver Code Ends
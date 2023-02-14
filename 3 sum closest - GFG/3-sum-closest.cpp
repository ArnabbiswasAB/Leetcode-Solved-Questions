//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int n, int target)
    {
        // code here
        
        sort(A, A+n);
        int min_diff = INT_MAX;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            
            int left = i+1, right = n-1;
            
            while(left < right){
                
                int sum = A[left] + A[i] + A[right];
                
                if(sum == target)
                return sum;
                
                if(abs(target - sum) < min_diff){
                    min_diff = abs(target - sum);
                    ans = sum;
                }
                
                if(sum > target)
                right--;
                else if(sum < target)
                left++;
            }
            
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
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends
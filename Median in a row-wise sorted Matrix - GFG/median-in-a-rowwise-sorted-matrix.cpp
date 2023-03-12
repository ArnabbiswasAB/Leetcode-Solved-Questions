//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
   int countLessThanMid(vector<int> arr, int x)
    {
        //since every row is sorted
        int start = 0;
        int end = arr.size()-1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(arr[mid] <= x)
                start = mid+1;
            else
                end = mid-1;
        }
        return start;
    }    
 

    int median(vector<vector<int>> &arr, int m, int n)

    {

        int low = 1;
        int high = 1e9;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int count=0;
            for(int i=0;i<m;i++)
            {
                count += countLessThanMid(arr[i], mid);
            }
            if(count <= (m*n)/2)
                low = mid+1;
           else
                high = mid-1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends
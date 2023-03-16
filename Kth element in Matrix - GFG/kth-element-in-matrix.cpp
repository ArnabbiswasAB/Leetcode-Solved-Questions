//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int binarySearch(int arr[],int n, int x){
    
    int low =0, high = n - 1;
    
    while(low <= high){
        
        int mid = low + (high - low)/2;
        
        if(arr[mid] <= x)
        low = mid + 1;
        else
        high = mid - 1;
    }
    
    return low;
}


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  
    int low = mat[0][0], high = mat[n-1][n-1];
    
    while(low < high){
        
        int count = 0;
        int mid  = low + (high - low)/2;
        
        for(int i=0; i<n; i++){
            count += binarySearch(mat[i],n, mid);
        }
        
        if(count < k)
          low = mid + 1;
          else
          high = mid ;
    }
    
    return low;
}

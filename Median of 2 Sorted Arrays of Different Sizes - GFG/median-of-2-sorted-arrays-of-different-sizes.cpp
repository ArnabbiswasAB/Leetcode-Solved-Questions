//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr, vector<int>& brr)
    {
        // Your code goes here
        
        if(arr.size() > brr.size()) 
        return MedianOfArrays(brr, arr);
        
        int n = arr.size();
        int m = brr.size();
        int low = 0, high = n;
        
       while(low<=high){
           
           int cut1 = (low + high)/2;
           int cut2 = (n+m+1)/2 - cut1;
           
           int left1 = cut1 == 0 ? INT_MIN : arr[cut1-1];
           int left2 = cut2 == 0 ? INT_MIN : brr[cut2-1];
           
           int right1 = cut1 == n ? INT_MAX : arr[cut1];
           int right2 = cut2 == m ? INT_MAX : brr[cut2];
           
           if(left1 <= right2 && left2 <= right1){
               if((n+m)%2 == 0){
                   return ((double)(max(left1,left2) + min(right1,right2))/2);
               }
               else{
                   return ((double)max(left1,left2));
               }
           }
           else if(left1 > right2){
               high = cut1 - 1;
           }else
           low = cut1 + 1;
       }
      return 0.0;  
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
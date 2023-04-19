//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(long long arr[],long long low, long long mid, long long high){
       
       long long total = 0;
       long long j = mid + 1;
       
       for(long long i=low; i<=mid; i++){
           
           while(j<=high && arr[i] > arr[j])
           j++;
           
           total += (j - (mid + 1));
       }
       
      
      long long left = low, right = mid + 1;
      vector<long long>temp;
      
       while(left<=mid && right<= high){
           if(arr[left] <= arr[right])
           temp.push_back(arr[left++]);
           else
           temp.push_back(arr[right++]);
       }
       
       while(left <= mid){
           temp.push_back(arr[left++]);
       }
       
       while(right <= high){
           temp.push_back(arr[right++]);
       }
       
       for(long long i=low; i<=high; i++){
           arr[i] = temp[i - low];
       }
       
       return total;
    }
    
    
    long long mergeSort(long long arr[],long long low,long long high){
        
        long long inv_count = 0;
        
        if(low>=high)
        return 0;
        
        long long mid = low + (high - low)/2;
        
        inv_count = mergeSort(arr, low, mid);
        inv_count += mergeSort(arr, mid+1, high);
        
        inv_count += merge(arr, low, mid, high);
        return inv_count;
    }
   
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        
        return mergeSort(arr, 0, N-1);
    }

};




//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(long long arr[],long long int temp[],long long int start, long long mid, long long end){
        
        long long int inv_count = 0;
        
        long long int i = start , k = start, j = mid;
        
        
        while(i<= mid - 1 && j<=end){
            
            if(arr[i] <= arr[j])
             temp[k++] = arr[i++];
            else{
                temp[k++] = arr[j++];
                inv_count += mid - i;
            } 
        }
        
        while(i<=mid-1)
        temp[k++] = arr[i++];
        
        while(j<=end)
        temp[k++] = arr[j++];
        
        for(int l = start; l<= end; l++)
         arr[l] = temp[l];
         
        return inv_count; 
    }
    
    
    long long int mergeSort(long long arr[], long long int temp[],
    long long int start,long long int end){
        
        
        long long int inv_count = 0;
        
        if(start<end){
            
            long long mid = (start + end)/2;
            inv_count += mergeSort(arr, temp, start,mid);
            inv_count += mergeSort(arr, temp, mid+1, end);
            
            inv_count += merge(arr, temp, start, mid + 1, end);
        }
        
        return inv_count;
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        
       long long int temp[N];
       
       return mergeSort(arr,temp, 0 , N-1);
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
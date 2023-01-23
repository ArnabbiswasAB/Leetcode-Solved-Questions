//{ Driver Code Starts
// A Sample C++ program for beginners with Competitive Programming

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int arr[], int n)
    {
       //Your code here
       
       /**************
        * No need to print the array
        * ************/
        
         int low = 0, high = n-1;

	 while(low < high){
         
		 if(arr[low] == 1 && arr[high] == 0){
              swap(arr[low],arr[high]);
			  low++;
			  high--;
		 }
		 else if(arr[low] == 0)
		 low++;
		 else if(arr[high] == 1)
		 high--;
	 }


	 return ;
    }
};

//{ Driver Code Starts.
int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    Solution obj;
	    obj.binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}




// } Driver Code Ends
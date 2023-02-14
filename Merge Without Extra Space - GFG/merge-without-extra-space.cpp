//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        
        /*
        step 1 - pick any array

step 2- compare last element of picked array to first element of second array

if (picked > second) swap them

      decrease the counter for picked array

      and increase the counter for second array

step 3 -  break the loop if codition is false or you reached the first element of picked array

 

step 4 - sort both the array using heap sort because it does not use any extra space

 

complexity is -

time - max(n log(n) , m log(m))

or accuratly we can say - n log(n) + m log(m)

which is less than or equal to  -  (n+m) log(n+m)

space - O(1)
        */
        void merge(long long a[], long long b    [], int n, int m) 
        { 
            // code here 
            
              int i=n-1;
       int j = 0;
       while(i>=0 and j<m and a[i]>b[j]){
            swap(a[i--],b[j++]);
       }
       sort(a,a+n);
       sort(b,b+m);
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends
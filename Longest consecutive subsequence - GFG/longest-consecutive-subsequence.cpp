//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int>st(arr, arr+N);
        
        int ans = 1;
        
        for(int i=0; i<N; i++){
            
            if(st.find(arr[i] - 1) != st.end())
            continue;
            else{
                int count = 1, curr = arr[i];
                
                while(st.find(curr + 1) != st.end()){
                    count++;
                    curr += 1;
                }
                
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
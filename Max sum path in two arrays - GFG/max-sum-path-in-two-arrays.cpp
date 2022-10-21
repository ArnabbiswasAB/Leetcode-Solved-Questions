// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int arr1[], int arr2[], int l1, int l2)
    {
    
        //Your code here
         int sum1 = 0, sum2 = 0, i = 0, j = 0, result = 0;
        while(i < l1 && j < l2){
            if(arr1[i] < arr2[j]) 
            sum1 += arr1[i++];
            else if(arr2[j] < arr1[i])
            sum2 += arr2[j++];
            else{
                // Both equal so adding either of the two
                result += max(sum1, sum2) + arr1[i];
                sum1 = sum2 = 0;
                i++,j++;
            }
        }
        
        //if length is unqueal so these cases.
        while(i < l1)
        sum1 += arr1[i++];
        while(j < l2)
        sum2 += arr2[j++];
        return result + max(sum1,sum2);
   
        
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

  // } Driver Code Ends
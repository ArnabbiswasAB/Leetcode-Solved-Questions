//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int>>ans;
     
    void helper(vector<int>& arr,int ind, int n, vector<int>& temp){
        
        ans.push_back(temp);
        
        for(int i=ind; i<n; i++){
            
            if(i>ind && arr[i] == arr[i-1])
              continue;
              
            temp.push_back(arr[i]);
            helper(arr, i+1, n, temp);
            temp.pop_back();
            
        }
    } 
    
    
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        // code here 
        sort(arr.begin(), arr.end());
        vector<int>temp;
        helper(arr, 0, n, temp);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends
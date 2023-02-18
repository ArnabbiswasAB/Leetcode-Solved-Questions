//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>>ans;
    
    void backtrack(vector<int>& nums, int target, vector<int>& temp, int ind, int sum){
         
         if(target == sum){
             ans.push_back(temp);
             return;
         }    
         
         if(ind == nums.size())
         return;
         
         for(int i = ind; i<nums.size(); i++){
             
             if(i>ind && nums[i] == nums[i-1])
             continue;
             
             if((nums[i] + sum) <= target){
                 temp.push_back(nums[i]);
                 backtrack(nums, target, temp,i, sum + nums[i]);
                 temp.pop_back();
             }
         }
    }
    
    
    vector<vector<int>>combinationSum(vector<int> &A, int B) {
        // Your code here
        
        vector<int>temp;
        sort(A.begin(),A.end());
        backtrack(A,B,temp,0,0);
        sort(ans.begin() , ans.end());
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
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
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
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){

        
        map<int, vector<int>> mp;
        
        for(int i=0; i<N; i++){
            mp[arr[i]].push_back(i);
        }
        
        
        int low = 1;
        for(auto it : mp){
            vector<int>temp = it.second;
            
            for(int i=0; i<temp.size(); i++){
                arr[temp[i]] = low;
            }
            
            low++;
        }
        
        return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
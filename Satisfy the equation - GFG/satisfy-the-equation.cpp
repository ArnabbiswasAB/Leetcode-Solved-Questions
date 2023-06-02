//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int arr[], int n) {
        
        
        
        unordered_map<int,pair<int,int>> mp;
        set<vector<int>> st;
        vector<int> temp(4,-1);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(mp.find(arr[i]+arr[j])!=mp.end()){
                    temp[0]=mp[arr[i]+arr[j]].first;
                    temp[1]=mp[arr[i]+arr[j]].second;
                    temp[2] = i;
                    temp[3] = j;
                    if(temp[0]!=temp[2] && temp[0]!=temp[3] && temp[1]!=temp[2] && temp[1]!=temp[3])
                        st.insert(temp);
                }
                else
                mp[arr[i]+arr[j]]={i,j};
            }
        }
        if(temp[0]==-1)
            return temp;
        return *(st.begin());
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends
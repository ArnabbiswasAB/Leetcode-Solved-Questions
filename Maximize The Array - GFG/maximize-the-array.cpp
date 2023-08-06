//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
           
           
             vector<int> ans;
        set<int> st;
        
        // put all elements into the set
        for(int i=0; i<n; i++){
            st.insert(arr2[i]);
            st.insert(arr1[i]);
        }
        
        //consider the only last n elements of set , beacouse these values will be giving the maximal sum
        while(st.size() > n){
            st.erase(*st.begin());
        }
        
        //firstly puting all the elements of arr2 that are present in set
        for(int i=0; i<n; i++){
            if(st.find(arr2[i]) != st.end()){
                ans.push_back(arr2[i]);
                st.erase(arr2[i]);//make sure to erase the taken element in set
            }
        }
       
       //lastly puting all the elements of arr1 that are present in set
        for(int i=0; i<n; i++){
            if(st.find(arr1[i]) != st.end()){
                ans.push_back(arr1[i]);
                st.erase(arr1[i]); // make sure to erase the taken element in set
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
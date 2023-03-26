//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    vector<long long> getDigitDiff1AndLessK(long long *arr, int n, long long k) {
   
     vector<long long > v;
        for(int i=0;i<n;i++){
            if(arr[i]>9 && arr[i]<k){
                int temp=arr[i];
                bool ans=true;
                while(temp>9){
                    int a=temp%10;
                    temp/=10;
                    int b=temp%10;
                    if(abs(a-b)!=1){
                        ans=false;
                        break;
                    }
                }
                if(ans==true){
                    v.push_back(arr[i]);
                }
            }
        }
        if(v.empty()){
            v.push_back(-1);
        }
        return v;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        long long arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        auto ans = obj.getDigitDiff1AndLessK(arr, n, k);
        for (auto x: ans) {
            cout << x << " ";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";

    }
    return 0;
}

// } Driver Code Ends
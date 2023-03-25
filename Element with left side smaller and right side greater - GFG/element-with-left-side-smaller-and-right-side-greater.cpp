//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    
    vector<int>prefix(n,0),suffix(n,0);
    prefix[0]=arr[0],suffix[n-1]=arr[n-1];
    
    for(int i=1;i<n;i++){
        prefix[i]=max(prefix[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        suffix[i]=min(suffix[i+1],arr[i]);
    }
    for(int i=1;i<n-1;i++){
        if(arr[i]>=prefix[i-1] && arr[i]<=suffix[i+1]){
            return arr[i];
        }
    }
    return -1;
    
}
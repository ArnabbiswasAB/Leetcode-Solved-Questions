//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
   
     long long ans=0;
    
    ans=1;//for only aaaa
    ans+=2*n;//for 1b or 1c and rest a;
    ans+=n*(n-1);//for 1b and 1c and rest a;
    ans+=n*(n-1)*(n-2)/2;//for 1b ,2c and rest a;
    ans+=n*(n-1)/2;
    
    return ans;
  
}
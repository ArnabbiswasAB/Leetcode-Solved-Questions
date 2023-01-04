//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        int findNum(int n)
        {
        //complete the function here
        int low = 0;
            int high = n*5;
            int ans = high;
            while(low <= high){
                int mid = low + (high - low)/2;
                int count = 0;
                int num = 5;
                while(mid/num != 0){
                    count += mid/num;
                    num *= 5;
                }
                if(count < n){
                    low = mid + 1;
                }
                else{
                    ans = min(ans, mid);
                    high = mid - 1;
                }
            }
            return ans;
       
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends
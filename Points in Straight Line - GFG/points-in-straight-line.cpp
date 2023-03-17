//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
public:
    int maxPoints(int X[], int Y[], int N) {
       //code here
       
        int overall_max = 0;
     unordered_map<double,int> map;
     for(int i=0;i<N;i++)
     {
     for(int j=0;j<N;j++)
     {
         //fixed point
         if(i!=j)
         {
         int x = X[i];
         int y = Y[i];
         // varying point
         int temp_x = X[j];
         int temp_y = Y[j];
         if((temp_x-x)==0)
         {
             map[INT_MAX]++;
         }
         else
         {
             double slope =  (temp_y-y)/((temp_x-x)*1.0);
             map[slope]++;
         }
         }
     }
      for(auto i:map)
      {
          if(i.second>overall_max)
          overall_max = i.second;
      }
      map.clear();
     }
     return overall_max+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n], y[n];
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=0;i<n;i++){
            cin>>y[i];
        }
        Solution ob;
        cout << ob.maxPoints(x, y, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int arr[], int N)
    {
      // Stores the leftmost and rightmost
    // point of every sprinklers
    vector<pair<int, int> > V;
    // Traverse the array arr[]
    for (int i = 0; i < N; i++) {
        if (arr[i] > -1) {
            V.push_back(
                pair<int, int>(i - arr[i], i + arr[i]));
        }
    }
    // Sort the array sprinklers in
    // ascending order by first element
    sort(V.begin(), V.end());
 
    // Stores the rightmost range
    // of a sprinkler
    int maxRight = 0;
    // Stores minimum sprinklers
    // to be turned on
    int res = 0;
 
    int i = 0;
 
    // Iterate until maxRight is
    // less than N
    while (maxRight < N) {
 
        // If i is equal to V.size()
        // or V[i].first is greater
        // than maxRight
 
        if (i == V.size() || V[i].first > maxRight) {
            return -1;
        }
        // Stores the rightmost boundary
        // of current sprinkler
        int currMax = V[i].second;
 
        // Iterate until i+1 is less
        // than V.size() and V[i+1].first
        // is less than or equal to maxRight
        while (i + 1 < V.size()
               && V[i + 1].first <= maxRight) {
 
            // Increment i by 1
            i++;
            // Update currMax
            currMax = max(currMax, V[i].second);
        }
 
        // If currMax is less than the maxRight
        if (currMax < maxRight) {
            // Return -1
            return -1;
        }
        // Increment res by 1
        res++;
 
        // Update maxRight
        maxRight = currMax + 1;
 
        // Increment i by 1
        i++;
    }
    // Return res as answer
    return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends
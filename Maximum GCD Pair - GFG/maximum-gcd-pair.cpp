//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int MaxGcd(int n, int arr[]) { 
        //complete the function here  
        
       int m = 0;
    // Finding maximum element.
    for (int i = 0; i < n; i++)
    {
        m = max(m, arr[i]);
    }
    
    // Finding frequency of each element.
    vector<int> freq(m + 5, 0);
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = m; i > 0; i--)
    {
        int cnt = 0;
        for (int j = i; j <= m; j += i)
        {
            cnt += freq[j];
        }
        if (cnt > 1)
        {
            // i is a divisor of two or more elements.
            return i;
        }
    }
    return 1;
        
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
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.MaxGcd(n, a) << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends
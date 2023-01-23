//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int elements[], int n){
        // Code here
       int maximum = elements[n - 1];
    
    vector<int> answer;
    // Rightmost element is always a leader.
    answer.push_back(maximum);

    for (int i = n - 2; i >= 0; i--) {
        // If current element is greater than maximum.
        if (maximum <= elements[i]) {
            maximum = elements[i];
            answer.push_back(maximum);
        }
    }
    // To get original order.
    reverse(answer.begin(), answer.end());
    return answer;
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends
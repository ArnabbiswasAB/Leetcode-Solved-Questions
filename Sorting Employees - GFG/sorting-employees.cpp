//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;
struct node{
	int salary;
	string name;
};

// } Driver Code Ends
/* struct node{          // node structure
     int salary;
     string name;
 };
*/



class Solution{

	public:
	static bool comp(pair<string,int>& a, pair<string,int>& b){
	    
	    if(a.second == b.second)
	    return a.first < b.first;
	    
	    return a.second < b.second;
	}
	
	
	void sortRecords(node arr[], int n)
	{
	    // Your code goes here
	    
	    vector<pair<string,int>>v;
	    for(int i=0; i<n; i++)
	    v.push_back({arr[i].name, arr[i].salary});
	    
	    sort(v.begin(), v.end(), comp);
	    
	    for(int i=0; i<n; i++){
	        arr[i].name = v[i].first;
	        arr[i].salary = v[i].second;
	    }
	    
	    return;
	    
	}
	 

};

//{ Driver Code Starts.



int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        node arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i].name>>arr[i].salary;
        

        Solution ob;
        ob.sortRecords(arr, n);
        for(int i=0;i<n;i++)
        	cout<<arr[i].name<<" "<<arr[i].salary<<" ";
	    cout << "\n";
	     
    }
    return 0;
}







// } Driver Code Ends
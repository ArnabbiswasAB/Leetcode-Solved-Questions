//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int nums[], int n)
    {
        //code here.
        unordered_map<int,int>mp;
        
        unordered_set<int>st;
        
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        
        
        int size = st.size(), count = 0, j = 0;
     
        for(int i=0; i<n; i++){
            
            mp[nums[i]]++;
            
            while(mp.size() == size){
                count += (n-i);
                
                
                mp[nums[j]]--;
                
                if(mp[nums[j]] == 0)
                mp.erase(nums[j]);
                
                 j++;
            }
            
           
        }
        
        return count;
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
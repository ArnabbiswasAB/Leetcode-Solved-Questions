//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item a , Item b){
     
      double a1 = (double)a.value/a.weight;
      double a2 = (double)b.value/b.weight;
      
      return a1>a2;
    }
    
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        int curweight = 0;
        double result = 0.0;
        
        sort(arr,arr+n,comp);
        
        for(int i=0; i<n; i++){
            
            int remain = W - curweight;
            
            int weight = arr[i].weight;
            int profit = arr[i].value;
            
            if(arr[i].weight <= remain){
                curweight += weight;
                result += profit;
            }else{
                result += (profit/(double)weight)*(double)remain;
                break;
            }
        }
        
        
        return result;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
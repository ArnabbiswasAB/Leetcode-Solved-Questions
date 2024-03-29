//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int n, int d) {
	    // Code here
	    
	   string ans = "";
       
        
        // Handling Negative Case
        if((n<0 && d>0) || (n>0 && d<0 ))
            ans+= '-';
        
        // To avoid Edge Cases Mentioned Below store Numerator and Denominator
        // in Long long datatype ans remainder as well
        
        long long a = abs(n);
        long long b = abs(d);
        
        // Calculation Integral Part Of Answer
        long long num = abs(a/b);
        
        // Storing that to our ans string
        ans += to_string(num);
        
        // Calculate Remainder
        long long rem = abs(a%b);
        
        
        // IF remainder is zero , there wont be decimal part so return ans
        if(rem == 0)
            return ans;
        
        ans.push_back('.');
        
        // Now We will calculate decimal part
        // we will store mapping of remainder with its appearing index 
        // ex : 1/10 => rem = 1 its index will be 0
        
        string dec = "";
        unordered_map<int, int> mp;
       
        
        while(rem)
        {
            // iF We come across any remainder which is present in mapping 
            // it means the recurring part start from that remainder and we will get its index 
            // and process the result
            if(mp.find(rem) != mp.end())
            {
                int index  = mp[rem];
                string recurring = dec.substr(index);
                dec.erase(index);
                dec += '(' + recurring + ')';
                break;
            }
            // If Remainder dont exist in map we will continue dividing and storing next remainder till it becomes zero
            else
            {
                mp[rem] = dec.size();
                dec += to_string(rem*10/b);
                rem = (rem*10)%b;
            }
        }
        
        ans += dec;
        return ans;
	
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
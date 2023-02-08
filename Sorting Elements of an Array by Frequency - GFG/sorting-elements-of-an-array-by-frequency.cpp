#include<bits/stdc++.h>

using namespace std;

static bool comp(pair<int,int>& a, pair<int,int>& b){
    
    if(a.second == b.second)
       return a.first < b.first;
       
    return a.second > b.second;   
}


int frequency(int arr[], int n){
    
    unordered_map<int,int>mp;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }
    
    vector<pair<int,int>>v;
    for(auto it : mp){
        v.push_back({it.first, it.second});
    }
    
    sort(v.begin(),v.end(),comp);
    int j=0;
    
    for(int i=0; i<v.size(); i++){
        
        while(v[i].second--){
        arr[j] = v[i].first;
        j++;
      }
    }
    
    return 0;
}


int main()
 {
	//code
	
	int T;
	cin>>T;
	
	while(T--){
	   
	   int N;
	   cin>>N;
	   
	   int arr[N];
	   for(int i=0; i<N; i++){
	       cin>>arr[i];
	   }
	   
	   frequency(arr, N);
	   
	   for(int i=0; i<N; i++){
	       cout<<arr[i]<<" ";
	   }
	   
	   cout<<endl;
	}
	
	
	return 0;
}
class Solution {
public:
    bool isFeasible(vector<int>& bloomDay,int mid,int k,int required){
        int n = bloomDay.size();
        
        int boquets = 0;
        int subArraySize = 0;
        for(int i=0;i<n;i++){
			//if anywhere in between if we found any element that is greater than mid then
			//we cant use this subarray for creating a boquet within mid time
            if(bloomDay[i] > mid){
                subArraySize = 0;
            }
			//it means we have found k elements which are <= mid
			//and we can form a boquet with this subarray within mid time
            else if(++subArraySize == k){
                subArraySize = 0;
                boquets++;
            }
        }
        // cout<<endl;
        return boquets >= required;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int total = 1ll * m * k;
        
        if(total > n) return -1;
        
        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        
        
        int res = 1e9;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(isFeasible(bloomDay,mid,k,m)){
                res = min(res,mid);
                high = mid - 1;
            }
            else low = mid + 1;
        }
        
        return res;
    }
};
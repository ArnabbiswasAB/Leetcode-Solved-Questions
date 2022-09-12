class Solution {
public:
   int subArrayWithAtmostBdistinct(vector<int>&A, int B){
    int count =0;
    int left=0;
    unordered_map<int,int>mp;
    int ans =0;
    for(int right=0;right<A.size(); right++){
        mp[A[right]]++;
        if(mp[A[right]]==1){
            count++;
        }
        while(count>B){
            mp[A[left]]--;
            if(mp[A[left]]==0){
                count--;
            }
            left++;
        }
        ans += (right-left+1);
    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& A, int B) {
        return subArrayWithAtmostBdistinct(A,B)-subArrayWithAtmostBdistinct(A,B-1);
    }
};
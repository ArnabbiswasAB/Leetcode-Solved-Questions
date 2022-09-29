class Solution {
public:
    bool res;
    // function to get sum of target using nums and mask array
    void solve(int i, int csum, int tar , int k ,vector<int> &num , vector<bool> &mask){
        // if all subsets are having sum equal to target then we will call solve for k = 1 so update res and return 
        
        if(k == 1){  
            res = true; 
            return;
         }
        
        // if i is at the end or current sum is greater than target then return
        if(i == num.size() || csum > tar) return;
        // if current sum is equal to target then solve for next subset
        if(csum == tar) return solve(0,0,tar,k-1,num,mask);
        // if this element is not used then use it and solve recursively 
        if(!mask[i]){
            mask[i] = 1;
            solve(i+1,csum + num[i],tar, k, num , mask);
            mask[i] = 0;
        }
        // and also solve for not including i'th element 
        solve(i+1, csum , tar, k , num , mask);
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int allsum = 0;
        res = false;
        // getting allsum of nums elements
        for(int i: nums) allsum += i;
        // if allsum cannot be dived by k then subsets cannot exists
        if(allsum%k != 0) return 0;
        // sorting in decreasing order
        sort(nums.begin(), nums.end() , greater<int>());
        // making a mask vector to check status of used elements 
        vector<bool> mask(nums.size(),0);
        // calling solve function that will recursively solve and store result in res variable
        solve(0,0,allsum/k, k, nums , mask);
        return res;
    }
};
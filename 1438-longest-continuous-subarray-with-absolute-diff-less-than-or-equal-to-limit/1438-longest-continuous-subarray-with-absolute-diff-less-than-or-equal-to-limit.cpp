/*
Approach: Sliding Window 1 : Deque

Here we will maintain 2 deques.
1. maxDeque: to maintain maximum element in the window.
2. minDeque: to maintain minimum element in the window.

If maxDeque.front() - minDeque.front() > limit: Invalid Window : we will shrink it by removing elements 
from the start until we hit a valid window[maxDeque.front() - minDeque.front() <= limit]
*/
// TC: O(N)
// SC: O(N)
class Solution {
public:
    int longestSubarray(vector<int>& arr, int limit) {
        int i = 0, j = 0, n = arr.size(), maxLen = 0;
        deque<int> maX, miN;
        
        while(j < n){
            // Removing all smaller element then current element and then we will put current element.
            while(!maX.empty() && maX.back() < arr[j]) maX.pop_back();
            
            // Removing all greater element then current element and then we will put current element.
            while(!miN.empty() && miN.back() > arr[j]) miN.pop_back();
            
            maX.push_back(arr[j]);
            miN.push_back(arr[j]);
            
            // Invalid -> Valid Window
            while(maX.front() - miN.front() > limit && i < j){
                if(arr[i] == miN.front()) miN.pop_front();
                if(arr[i] == maX.front()) maX.pop_front();
                i++;
            }
            
            // We always hit a valid window, at this point.
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};

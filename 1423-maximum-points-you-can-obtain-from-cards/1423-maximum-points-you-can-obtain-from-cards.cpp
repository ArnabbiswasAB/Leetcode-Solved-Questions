class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        
      int i=0,j=0,total = 0,n = card.size();
      int size = n - k;
        
      for(auto i : card)
          total += i;
        
      int mini = INT_MAX, curr = 0;  
      for(i=0; i<size; i++)
          curr += card[i];
        
      mini = min(mini,curr);
        
      while(i<n){
          
          curr += card[i++];
          curr -= card[j++];
          
          mini = min(mini,curr);
      }  
        
        
        return (total - mini);
    }
};
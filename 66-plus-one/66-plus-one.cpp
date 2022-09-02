class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
      //  reverse(digits.begin(),digits.end());
        int n = digits.size();
        int carry = 1;
        for(int i = n - 1; i>=0; i--){
            
            int temp = digits[i] + carry;
           cout<<temp;
            digits[i] = temp%10;
          
            carry = temp/10;
        }
        
       if(carry > 0){
            digits.insert(digits.begin(),carry); 
           
        }
        
     //   reverse(digits.begin(), digits.end());
        
        return digits;
    }
};
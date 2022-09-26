class Solution {
public:
    int numberOfSubstrings(string s) {
        
        ////Important-> mai 'abc' agar abhi bna pa rha hu to aage bche hue jitne b char hai unhe ek ek krke add krke jo b substring bnegi unme b to 'abc' hoga hi hoga thats why ans+=(n-j);
                
         unordered_map<char,int> mp;
        int i=0,j=0,count=0;
		
		
        while(j<s.size()){
            mp[s[j]]++;
            while(mp.size()==3){
                count+=s.size()-j;  //
                // eg: abcabc 
                // j=2 i.e abc̲abc this means the possible answers are also
                // a̲b̲c̲a̲ ,abcab,abcabc i.e s.size()-j;
                
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
		
        return count;
    }
    
};
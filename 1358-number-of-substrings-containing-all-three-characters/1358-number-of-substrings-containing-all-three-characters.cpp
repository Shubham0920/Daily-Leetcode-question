class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int l=0;
        map<char,int> m;
        for(int r=0;r<s.size();r++){
            m[s[r]]++;
            if((r-l+1)>=3){
                while(m['a']>=1 && m['b']>=1 && m['c']>=1){
                    ans=ans+(s.size()-r);
                    m[s[l]]--;
                    l++;
                }
        }
            
        }
        // while(l<s.size() && m['a']>0 && m['b']>0 && m['c']>0){
        //     m[s[l]]--;
        //     l++;
        //     ans++;
        // }
        return ans;
    }
};
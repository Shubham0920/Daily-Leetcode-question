class Solution {
public:
    int lengthOfLongestSubstring(string st) {
        if(st.length()==0)return 0;
        int l=0;
        set<char> s;
        int ans = INT_MIN;
        for(int r=0;r<st.size();r++){
            if(s.find(st[r])!=s.end()){
                while(l<r && s.find(st[r])!= s.end()){
                    s.erase(st[l]);
                    l++;
                }
            }
            s.insert(st[r]);
            ans = max(ans,r-l+1);
        }
        return ans;
        
    }
};
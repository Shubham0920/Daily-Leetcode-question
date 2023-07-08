class Solution {
public:
    int maxConsecutive(int b, int t, vector<int>& s) {
        sort(s.begin(),s.end());
        int ans = 0;
        for(int i=0;i<s.size()-1;i++){
            ans = max(ans,s[i+1]-s[i]-1);
        }
        ans = max(ans,s[0]-b);
        ans = max(ans,t-s[s.size()-1]);
        return ans;
    }
};
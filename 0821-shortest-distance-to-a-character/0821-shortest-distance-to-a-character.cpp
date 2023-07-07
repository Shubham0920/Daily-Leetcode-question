class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans,e;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                e.push_back(i);
            }
        }
        for(int i=0;i<s.size();i++){
            int x=INT_MAX;
            for(int j=0;j<e.size();j++){
                x = min(x,abs(i-e[j]));
            }
            ans.push_back(x);
        }
        return ans;
    }
};
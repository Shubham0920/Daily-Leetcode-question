class Solution {
public:
    vector<vector<string>> ans;
    bool ispalindrom(string s,int st,int e){
        while(st<=e){
            if(s[st++] != s[e--]){
                return false;
            }
        }
        return true;
    }
    void solve(string s,int ind,vector<string> &vec){
        if(ind == s.size()){
            ans.push_back(vec);
        }
        for(int i=ind;i<s.length();i++){
            if(ispalindrom(s,ind,i)){
                vec.push_back(s.substr(ind,i-ind+1));
                solve(s,i+1,vec);
                vec.pop_back();
            }
        }
        
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s,0,temp);
        return ans;
    }
};
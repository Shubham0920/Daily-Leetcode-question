class Solution {
public:
    vector<string> ans;
    void solve(string &s,int open,int close){
        if(close == 0 && open == 0){
            ans.push_back(s);
            return;
        }
        if(open>0){
            s.push_back('(');
            solve(s,open-1,close);
            s.pop_back();
        }
        if(close>0 && open<close){
            s.push_back(')');
            solve(s,open,close-1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        solve(s,n,n);
        return ans;
    }
};
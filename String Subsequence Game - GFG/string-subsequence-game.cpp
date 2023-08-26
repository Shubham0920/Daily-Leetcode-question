//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void solve(int i,string s,set<string> &se,set<char> &v,string ans){
        if(i>=s.size()){
            return ;
        }
        for(int j=i;j<s.size();j++){
            ans.push_back(s[j]);
            if(v.find(s[j]) == v.end()){
                se.insert(ans);
            }
            solve(j+1,s,se,v,ans);
            ans.pop_back();
        }
    }
    set<string> allPossibleSubsequences(string s) {
        // code here
        set<string> se;
        set<char> v;
        v.insert('a');
        v.insert('e');
        v.insert('i');
        v.insert('o');
        v.insert('u');
        
        for(int i=0;i<s.size();i++){
            if(v.find(s[i]) != v.end()){
                string ans = "";
                ans += s[i];
                solve(i+1,s,se,v,ans);
            }
        }
        return se;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
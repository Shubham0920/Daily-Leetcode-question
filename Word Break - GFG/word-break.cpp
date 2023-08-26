//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    map<string,int> m;
    int solve(int i,string s){
        if(i==s.size()){
            return 1;
        }
        string ans = "";
        
        for(int j=i;j<s.size();j++){
            ans += s[j];
            if(m[ans]>0){
                // cout<<ans<<endl;
                if(solve(j+1,s)){
                    return 1;
                }
            }
        }
        return 0;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        for(auto x:B){
            m[x]++;
        }
        return solve(0,A);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
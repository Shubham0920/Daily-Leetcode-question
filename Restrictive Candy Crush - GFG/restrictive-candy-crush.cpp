//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        if(k == 1) return "";
        stack<pair<char,int>>st;
        for(int i = 0;i<s.length();i++){
            if(st.size()==0 || st.top().first != s[i]) 
                 st.push({s[i],1});
            else if(st.top().first == s[i]){
                if(st.top().second==k-1){
                    while(st.size()>0&&st.top().first == s[i]) 
                         st.pop();
                }
                else st.push({s[i], st.top().second+1});
            }
           
        }
        string ans = "";
        while(st.size()>0) {
            ans+= st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }



};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends
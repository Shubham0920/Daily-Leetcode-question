//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        int ans = INT_MIN;
        int end = s.size();
        while(!st.empty()){
            int x = st.top();
            st.pop();
            ans = max(ans,end-x-1);
            end = x;
        }
        ans = max(ans,end);
        return ans;
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
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends
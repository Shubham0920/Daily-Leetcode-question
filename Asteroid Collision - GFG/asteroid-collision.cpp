//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sign(int x){
        if(x>=0){
            return 1;
        }
        else{
            return -1;
        }
    }
    vector<int> asteroidCollision(int N, vector<int> &a) {
        // code here
        stack<int> st;
       
        for(int i=0;i<a.size();i++){
             bool flag = false;
            while(!st.empty() && sign(st.top())== 1 && sign(a[i]) == -1){
                if(abs(st.top())>abs(a[i])){
                    flag = true;
                    break;
                }
                else if(abs(st.top())==abs(a[i])){
                    flag = true;
                    st.pop();
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(!flag){
                st.push(a[i]);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
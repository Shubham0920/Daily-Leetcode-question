//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
   int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> left(n),right(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = 0;
            }
            else{
                left[i] = st.top()+1;
            }
            st.push(i);
        }

        stack<int> st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && h[st1.top()]>=h[i]){
                st1.pop();
            }
            if(st1.empty()){
                right[i] = n-1;
            }
            else{
                right[i] = st1.top()-1;
            }
            st1.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,(right[i]-left[i]+1)*h[i]);
        }

        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> p;
        for(int i=0;i<m;i++){
            p.push_back(M[0][i]);
        }
        int ans = largestRectangleArea(p);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] == 1){
                    p[j] += 1;
                }
                else{
                    p[j] = 0;
                }
            }
            ans = max(ans,largestRectangleArea(p));
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
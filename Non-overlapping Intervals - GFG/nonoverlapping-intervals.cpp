//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(int N, vector<vector<int>> &in) {
        // code here
        sort(in.begin(),in.end());
        vector<int> vis(N,0);
        int start ,end;
        int cnt = 0;
        int i = 0,j=1;
        while(j<N){
            if(in[i][1]<=in[j][0]){
                i = j;
                j++;
            }
            else if(in[i][1]<=in[j][1]){
                j++;
                cnt++;
            }
            else if(in[i][1]>= in[j][1]){
                cnt++;
                i=j;j++;
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends
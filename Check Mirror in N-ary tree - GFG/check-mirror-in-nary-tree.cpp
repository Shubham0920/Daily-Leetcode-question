//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        vector<vector<int>> g1(n+1);
        for(int i=0;i<2*e;i+=2){
            g1[A[i]].push_back(A[i+1]);
        }
        vector<vector<int>> g2(n+1);
        for(int i=0;i<2*e;i+=2){
            g2[B[i]].push_back(B[i+1]);
        }
        
        for(int i=1;i<=n;i++){
            vector<int> temp = g1[i];
            // for(auto x:temp){
            //     cout<<x<<" ";
            // }
            // cout<<endl;
            reverse(temp.begin(),temp.end());
            if(temp.size()>0 && temp != g2[i]){
                return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends
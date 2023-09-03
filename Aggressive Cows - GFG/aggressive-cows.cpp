//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool cowweput(vector<int>&s,int n,int mid,int k){
        int cnt = 1;
        int last = s[0];
        for(int i=1;i<n;i++){
            if(s[i]-last>=mid){
                cnt++;
                last = s[i];
            }
            if(cnt>=k)return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &s) {
    
        // Write your code here
        sort(s.begin(),s.end());
        int l = 0;
        int h = 1e9;
        int ans = -1;
        while(l<=h){
            int mid = (l+h)/2;
            if(cowweput(s,n,mid,k)){
                l = mid+1;
            }
            else{
                h = mid-1;
          
            }
        }
        return h;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
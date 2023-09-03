//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int solve(vector<int>&s,int n,int mid){
        int cnt = 0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=s[i];
            if(sum>mid){
                cnt++;
                sum = 0;
            }
        }
        return cnt;
    }
    int maxSweetness(vector<int>& s, int n, int k) {
    // Write your code here.
        int l = 0;
        int h = 1e9;
        int ans = -1;
        while(l<=h){
            int mid = (l+h)/2;
            int p = solve(s,n,mid);
            if(p>=k+1){
                l = mid+1;
            }
            else{
                ans = mid;
                h = mid-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends
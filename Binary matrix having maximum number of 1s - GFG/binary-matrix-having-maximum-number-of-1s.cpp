//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> m, int n) {
        //code here
        int mn=INT_MAX;
        int row=0;
        int count=0;
        
        for(int i=0;i<n;i++){
                int ind = lower_bound(m[i].begin(),m[i].end(),1)-m[i].begin();
                if(ind < mn){
                    mn=ind;
                    row=i;
                    count=n-ind;
                }
        }
        return {row,count};
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends
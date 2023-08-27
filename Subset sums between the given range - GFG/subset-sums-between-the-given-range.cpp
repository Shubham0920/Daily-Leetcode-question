//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    long long int cnt = 0;
    void solve(int i,vector<int>&arr, int n, int l, int r,int sum){
        if(i>=n){
            if(sum>=l && sum<=r){
                cnt++;
            } 
            return ;
        }
        solve(i+1,arr,n,l,r,sum+arr[i]);
        solve(i+1,arr,n,l,r,sum);
    }
    long long int countSubsets(vector<int>&arr, int n, int l, int r){
        //Write your code here
        solve(0,arr,n,l,r,0);
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    int l, r;
	    cin >> l >> r;
	    Solution ob;
	    long long int ans = ob.countSubsets(arr, n, l, r);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends
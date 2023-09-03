//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int lessthank(int m,int n,int mid){
        int sum = 0;
        for(int i=1;i<=m;i++){
            sum += min(mid/i,n);
        }
        return sum;
    }
    int KthSmallest(int m, int n, int k) {
        //Write your code here
        int l = 1;
        int h = m*n;
        int ans = -1;
        while(l<=h){
            int mid = (l+h)/2;
            int  p = lessthank(m,n,mid);
            if(p<k){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return l;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n, k;
	    cin >> m >> n >> k;
	    Solution ob;
	    int ans = ob.KthSmallest(m, n, k);
	    cout << ans << endl;
	}
	return 0;
}

// } Driver Code Ends
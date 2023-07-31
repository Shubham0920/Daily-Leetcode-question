//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	if(n <= 0)
            return 0;
        vector<pair<int, int>> vp;
        int res = 0;
        int prev = 0;
        for(int i=0; i<n; ++i)
            vp.push_back({arr[i],dep[i]});
        sort(vp.begin(), vp.end());
        vector<int> vis(n,0);
        for(int i=0; i<n; ++i) {
           if(vis[i] == 0){
                int prev=i;
                vis[i] = 1;
                for(int j=i+1;j<n;j++){
                    if(vis[j]==0 && vp[j].first > vp[prev].second) {
                        vis[j] = 1;
                        prev = j;
                    }
                }
                res++;
           }
        }
        return res;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
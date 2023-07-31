//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        //Your code here
        if(n <= 0)
            return 0;
        vector<pair<int, int>> vp;
        int res = 1;
        int prev = 0;
        for(int i=0; i<n; ++i)
            vp.push_back({p[i].second, p[i].first});
        sort(vp.begin(), vp.end());
        for(int i=1; i<n; ++i) {
            if(vp[i].second > vp[prev].first) {
                ++res;
                prev = i;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
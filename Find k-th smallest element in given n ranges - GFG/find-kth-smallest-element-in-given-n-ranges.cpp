//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&r, int q, vector<int>queries){
        //Write your code here
        sort(r.begin(),r.end());
        vector<vector<int>> vec;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                int start = r[i][0];
                int end = r[i][1];
                vis[i] = 1;
                for(int j=i+1;j<n;j++){
                    if(vis[j] == 0 && r[j][0]<=end){
                        vis[j] = 1;
                        end = max(end,r[j][1]);
                    }
                }
                vec.push_back({start,end});
            }
        }
        vector<int> ans;
        for(int i=0;i<q;i++){
            int k = queries[i];
            bool flag = false;
            for(int j=0;j<vec.size();j++){
                int x = vec[j][1]-vec[j][0]+1;
                if(k<=x){
                    flag = true;
                    ans.push_back(vec[j][0]+k-1);
                    break;
                }
                else{
                    k -= (vec[j][1]-vec[j][0]+1);
                }
            }
            if(!flag)ans.push_back(-1);
        }
        return ans;
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
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends
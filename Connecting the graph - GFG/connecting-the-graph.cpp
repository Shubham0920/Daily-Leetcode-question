//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> parent,rank;
	int findpar(int a){
	    if(a==parent[a]){
	        return a;
	    }
	    return parent[a] = findpar(parent[a]);
	}
	void union_(int a,int b){
	    int para = findpar(a);
	    int parb = findpar(b);
	    if(para==parb) return ;
	    if(rank[para]<rank[parb]){
	        parent[para] = parb;
	    }
	    else if(rank[para]>rank[parb]){
	        parent[parb] = para;
	    }
	    else{
	        parent[para] = parb;
	        rank[parb]++;
	    }
	}
    int makeConnected(int n, vector<vector<int>>& c) {
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        int cnt = 0;
        for(int i=0;i<c.size();i++){
            int a = c[i][0];
            int b = c[i][1];
            if(findpar(a)!=findpar(b)){
                union_(a,b);
            }
            else{
                cnt++;
            }
        }
        int comp = 0;
        for(int i=0;i<n;i++){
            if(i == parent[i]){
                comp++;
            }
        }
        if(cnt>=comp-1){
            return comp-1;
        }
        return -1;
    }
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        return makeConnected(n,edge);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
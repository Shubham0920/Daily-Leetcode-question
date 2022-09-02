class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int par(int n){
        if(n == parent[n]){
            return n;
        }
        return parent[n] = par(parent[n]);
    }
    void union_(int x,int y){
        int parx = par(x);
        int pary = par(y);
        
        if(rank[parx]<rank[pary]){
            parent[parx] = pary;
        }
        else  if(rank[parx]>rank[pary]){
            parent[pary] = parx;
        }
        else{
            parent[pary] = parx;
            rank[parx]++;
        }
    }
    vector<bool> areConnected(int n, int t, vector<vector<int>>& q) {
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            rank[i] = 0;
            parent[i] = i;
        }
        for(int i = t + 1;i<=n;i++)
        {
            for(int j = 2*i;j<=n;j+=i)
            {
                union_(i,j);
            }
        }
        
        vector<bool> ans;
        for(auto it:q)
        {
            ans.push_back(par(it[0])==par(it[1]));
        }
        return ans;
        // vector<bool> ans;
        // for(int i=0;i<q.size();i++){
        //     int x = q[i][0]-1;
        //     int y = q[i][1]-1;
        //     if(parent[x] == parent[y]){
        //         ans.push_back(true);
        //     }
        //     else{
        //         ans.push_back(false);
        //     }
        // }
        // return ans;
    }
};
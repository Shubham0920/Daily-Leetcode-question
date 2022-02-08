class Solution {
public:
    int find(int x,vector<int> &root,vector<int> &rank){
        if(x == root[x]){
            return x;
        }
        return root[x] = find(root[x],root,rank);
    }
    void union_set(int x,int y,vector<int> &root,vector<int> &rank){
        int rootx = find(x,root,rank);
        int rooty = find(y,root,rank);
        if(rootx != rooty){
            if(rank[rootx]>rank[rooty]){
                root[rooty] = rootx;
            }
            else if(rank[rootx]<rank[rooty]){
                root[rootx] = rooty;
            }
            else{
                root[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> root(n);
        vector<int> rank(n);
        for(int i=0;i<n;i++){
            root[i] = i;
            rank[i] = 1;
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    union_set(i,j,root,rank);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(root[i] == i){
                count++;
            }
        }
        return count;
    }
};
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int func(int i,int N,vector<int> colors[],int currColor,vector<vector<int>>&t){
    
            if(i==N) return 0;
        
        
           
           if(t[i][currColor]!=-1) return t[i][currColor];
           
           if(currColor==0)
           {
               
            return t[i][currColor]= min( colors[i][0]+func(i+1,N,colors,1,t),min( colors[i][1]+func(i+1,N,colors,2,t),colors[i][2]+func(i+1,N,colors,3,t) ) );
           }
           
           if(currColor==1){
               return t[i][currColor]= min( colors[i][1]+func(i+1,N,colors,2,t),colors[i][2]+func(i+1,N,colors,3,t) );
           }
           
           
           
           if(currColor==2){
               return t[i][currColor]= min( colors[i][0]+func(i+1,N,colors,1,t),colors[i][2]+func(i+1,N,colors,3,t) );
           }
           
           if(currColor==3){
               return t[i][currColor]= min( colors[i][1]+func(i+1,N,colors,2,t),colors[i][0]+func(i+1,N,colors,1,t) );
           }
           
}
    // int minCost(vector<vector<int>> &colors, int N) {
    //     // Write your code here.
    //     vector<vector< int>>t(N,vector<int>(5,-1));
    //     return func(0,N,colors,0,t);
    // }
    int minCost(int N, vector<int> cost[]) {
        // code here
        
        vector<vector< int>>t(N,vector<int>(5,-1));
        return func(0,N,cost,0,t);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> cost[N];
        int x, y, z;
        for(int i = 0;i < N;i++){
            cin>>x>>y>>z;
            cost[i].push_back(x);
            cost[i].push_back(y);
            cost[i].push_back(z);
        }
        
        Solution ob;
        cout<<ob.minCost(N, cost)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
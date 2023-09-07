//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> pq;
        pq.push({start,0});
        int mod = 100000;
        vector<int> dist(100000,1e9);
        dist[start] = 0;
        if(start==end)
        {
            return 0;
        }
        while(!pq.empty()){
            int step = pq.front().second;
            int num = pq.front().first;
            pq.pop();
            for(auto x:arr){
                int it = (x*num)%mod;
                if(step+1<dist[it]){
                    dist[it] = step+1;
                    if(it == end)return dist[it];
                    pq.push({it,step+1});
                }
            }
        }
        return -1;
        // queue<pair<int,int>> q;
        // q.push({start,0});
        //  int mod=100000;
        // vector<int> dist(100000,1e9);
        // dist[start]=0;
       
        // if(start==end)
        // {
        //     return 0;
        // }
        // while(!q.empty())
        // {
        //     int nd=q.front().first;
        //     int stp=q.front().second;
        //     q.pop();
        //     for(auto i:arr)
        //     {
        //         int n=(nd*i)%mod;
        //         if(stp+1<dist[n])
        //         {
        //             dist[n]=stp+1;
        //              if(n==end)
        //     {
        //         return stp+1;
        //     }
        //             q.push({n,stp+1});
        //         }
        //     }
        // }
        // return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
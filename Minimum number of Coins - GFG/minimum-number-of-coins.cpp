//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> ans;
        ans.push_back(2000);
        ans.push_back(500);
        ans.push_back(200);
        ans.push_back(100);
        ans.push_back(50);
        ans.push_back(20);
        ans.push_back(10);
        ans.push_back(5);
        ans.push_back(2);
        ans.push_back(1);
            
        vector<int> a;
        while(N>0){
            for(int i=0;i<ans.size();i++){
                if(N/ans[i] != 0){
                    int x = N/ans[i];
                    N = N%ans[i];
                    while(x--){
                        a.push_back(ans[i]);
                    }
                }
            }
        }
        return a;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
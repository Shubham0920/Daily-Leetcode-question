//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    long solve(long h[],long a[],long l,long mid,long n){
        long ans = 0;
        for(int i=0;i<n;i++){
            if(h[i]+mid*a[i]>=l){
                ans+=h[i]+mid*a[i];
            }
        }
        return ans;
    }
    
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        // code here
        long  l = 0;
        long h = 1e9;
        long ans = -1;
        while(l<=h){
            long mid = (l+h)/2;
            long speed = solve(H,A,L,mid,N);
            if(speed>=M){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
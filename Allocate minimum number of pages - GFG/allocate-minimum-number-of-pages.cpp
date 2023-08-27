//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int count(int A[],int N,int mid){
        int page = 0;
        int cnt = 1;
        for(int i=0;i<N;i++){
            if(page+A[i]<=mid){
                page += A[i];
            }
            else{
                cnt++;
                page = A[i];
            }
        }
        return cnt;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int l = INT_MIN;
        int h = 0;
        for(int i=0;i<N;i++){
            l = max(A[i],l);
            h += A[i];
        }
        int ans = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            int x = count(A,N,mid);
            if(x>M){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
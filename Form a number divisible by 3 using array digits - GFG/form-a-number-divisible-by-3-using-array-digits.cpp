//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sum( int num ){
        
        int ans = 0 ;
        
        while( num ){
            
            ans += num % 10;
            
            num = num / 10;
            
        }
        
        return ans;
        
    }
    
    int isPossible(int N, int arr[]) {
        // code here
        
        int sumDigit = 0;
        
        for( int i = 0 ; i < N ; ++ i ){
            sumDigit += sum( arr[i] );
        }
        
        return sumDigit % 3 == 0;
    }
};
    

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
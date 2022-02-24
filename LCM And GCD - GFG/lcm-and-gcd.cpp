// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long gcd(long long m , long long n){
        if(n == 0){
            return m;
        }
        return gcd(n,m%n);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
       vector<long long> ans;
       long long gc = gcd(A,B);
       long long lcm = A*B/gcd(A,B);
       ans.push_back(lcm);
       ans.push_back(gc);
       
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends
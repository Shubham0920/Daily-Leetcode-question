// { Driver Code Starts

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool isPrime(int N){
        if(N == 1) return 0;
        for(int i=2;i*i<=N;i++){
            if(N%i == 0) return 0;
        }
        
        return 1;
    }
    string isSumOfTwo(int N){
        if(N%2 != 0){
            if(isPrime(N-2)){
                return "Yes";
                
            }
            else{
                return "No";
            }
        }
        else{
            if(N==4){
                return "Yes";
            }
            else{
                for(int i=3;i<N/2;i=i+2){
                    if(isPrime(i) && isPrime(N-i)){
                        return "Yes";
                    }
                }
                return "No";
            }
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}
  // } Driver Code Ends
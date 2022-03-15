// { Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long maxProduct(int nums[], int n) {
        sort(nums,nums+n);
        long long max1 = 1,max2 = 1;
        // /int n = nums.size();
        max1 = (long long)nums[0]*nums[1]*nums[n-1];
        max2 = (long long)nums[n-3]*nums[n-2]*nums[n-1];
        // cout<<max1<<" "<<max2;
        return max(max1,max2);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
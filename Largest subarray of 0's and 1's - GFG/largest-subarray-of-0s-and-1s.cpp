// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int arr[], int n)
    {
        
    unordered_map<int, int> hM;
 
    int sum = 0; // Initialize sum of elements
    int max_len = 0; // Initialize result
    int ending_index = -1;
 
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;
 
    // Traverse through the given array
 
    for (int i = 0; i < n; i++) {
        // Add current element to sum
 
        sum += arr[i];
 
        // To handle sum=0 at last index
 
        if (sum == 0) {
            max_len = i + 1;
            ending_index = i;
        }
 
        // If this sum is seen before, then update max_len
        // if required
 
        if (hM.find(sum) != hM.end()) {
            if (max_len < i - hM[sum]) {
                max_len = i - hM[sum];
                ending_index = i;
            }
        }
        else // Else put this sum in hash table
            hM[sum] = i;
    }
        return max_len;
    }
};


// { Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
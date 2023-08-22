//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> nums;
        int fact = 1;
        for(int i=1;i<n;i++){
            nums.push_back(i);
            fact = fact*i;
        }
        k = k-1;
        string ans = "";
        nums.push_back(n);
        while(true){
            ans = ans + to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size() == 0){
                break;
            }
            k = k%fact;
            fact = fact/nums.size();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
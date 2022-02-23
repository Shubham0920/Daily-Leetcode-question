// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        int count =0;
        unordered_map<int, int> um;
        int curr_sum = 0;
        for (int i = 0; i < n; i++) {
            curr_sum += (arr[i] == 0) ? -1 : arr[i];
            um[curr_sum]++;
        }
    
        for (auto itr = um.begin(); itr != um.end(); itr++) {
     
            if (itr->second > 1)
                count += ((itr->second * (itr->second - 1)) / 2);
        }
     
        if (um.find(0) != um.end())
            count += um[0];
            
            return count;
        }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends
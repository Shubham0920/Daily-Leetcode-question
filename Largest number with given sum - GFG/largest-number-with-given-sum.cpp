//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
        int x = sum/9;
        int p = sum%9;
        string ans = "";
        while(x--){
            ans.push_back('9');
        }
        if(ans.size()==n && p == 0){
            return ans;
        }
        else if(ans.size()>=n){
            return "-1";
        }
        else{
            ans+=to_string(p);
            int rem = n-ans.size();
            while(rem--){
                ans.push_back('0');
            }
            return ans;
        }
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}
// } Driver Code Ends
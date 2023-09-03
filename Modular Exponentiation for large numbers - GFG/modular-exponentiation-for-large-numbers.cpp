//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    if(n == 0){
		        return 1;
		    }
		    if(n%2==0){
		        long long int p = PowMod(x,n/2,M)%M;
		        return (p%M*p%M)%M;
		    }
		    else{
		        long long int p = PowMod(x,n/2,M)%M;
		        return (x%M*(p%M*p%M)%M)%M;
		    }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends
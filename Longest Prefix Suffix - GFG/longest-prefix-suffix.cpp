//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    if(s.length() == 1) return 0;
	    
	    long long p =31;
	    long long mod = 1e9+7;
	    long long poww = 1;
	    
	    long long ph = 0;
	    long long sh = 0;
	    int ans = 0;
	    int n = s.size();
	    for(int i=0;i<s.size()-1;i++){
	        ph = ((ph*p)+(s[i]-'a'+1))%mod;
	        sh = ((sh + (s[n-i-1]-'a'+1)*poww)%mod)%mod;
	        poww = (poww*p)%mod;
	        
	        if(ph == sh){
	            ans = i+1;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends
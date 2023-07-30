//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
	public:
	string digitsNum(int N)
	{
	    // Code here.
	    int nine = N/9;
	    int num = N%9;
	    string ans = "";
	    if(num!=0){
	        ans += to_string(num);
	    }
	    while(nine--){
	        ans+='9';
	    }
	    N-= nine+1;
	    while(N--){
	        ans+='0';
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		string ans = ob.digitsNum(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
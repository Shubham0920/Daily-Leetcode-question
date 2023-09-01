//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int Count(int L, int R){
		    // Code here
		    vector<int> prime(R+1,1);
		    prime[0] = 0;
		    prime[1] = 1;
		    for(int i=2;i*i<=R;i++){
		        if(prime[i] == 1){
		            for (int p = i * i; p <= R; p += i)
                        prime[p] = 0;
		        }
		    }
		    int comp=0,pr=0;
		    if(L==1) L=2;
		    for (int p = L; p <= R; p++){
                if (prime[p]){
                     pr++;
                    //  cout<<p<<" ";
                }
                   
                else {
                    comp++;
                }
		    }
		  //  cout<<endl;
		  //  cout<<comp<<" "<<pr<<endl;
		    return comp-pr;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int L, R;
		cin >> L >> R;
		Solution obj;
		int ans = obj.Count(L, R);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
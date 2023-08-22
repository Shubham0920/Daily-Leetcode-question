//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    set<char> se;
		    set<char> s1;
		    string ans = "";
		    queue<char> q;
		    for(int i=0;i<A.size();i++){
		        if(se.find(A[i]) == se.end()){
		                q.push(A[i]);
		                ans += q.front();
		                se.insert(A[i]);
		        }
		        else{
		            s1.insert(A[i]);
		            while(!q.empty() && s1.find(q.front()) != s1.end()){
		                q.pop();
		            }
		            if(q.empty())ans+='#';
		            else ans+=q.front();
		            
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
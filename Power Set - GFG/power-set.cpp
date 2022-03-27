// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	void func(string s,int idx,string output,vector<string>& ans){
	        
	        if(idx==s.size()){
	            if(output.size()>0){
	                ans.push_back(output);
	            }
	            return ;
	        }
	        
	        // do not include s[idx]
	        func(s,idx+1,output,ans);
	        output+=s[idx];
	        
	        // include s[idx]
	        func(s,idx+1,output,ans);
	        
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		     vector<string> ans;
		    int idx=0;
		    string output="";
		    func(s,idx,output,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	vector<string> ans;
	void findpermute(string a,int l, int r){
	    if(l == r){
	        ans.push_back(a);
	    }
	    for(int i = l;i<=r;i++){
	        swap(a[l],a[i]);
	        findpermute(a,l+1,r);
	        swap(a[l],a[i]);
	    }
	}
	vector<string>find_permutation(string s)
	{
       findpermute(s,0,s.length()-1);
       sort(ans.begin(),ans.end());
       return ans;
	}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
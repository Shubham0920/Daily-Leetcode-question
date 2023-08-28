//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool comp(vector<int> dic1,vector<int> dic2){
        for(int i=0;i<26;i++){
            if(dic1[i] != dic2[i])return 0;
        }
        return 1;
    }
	int search(string pat, string txt) {
	    // code here
	    int n = pat.size();
	    vector<int> dic1(26,0);
	    for(int i=0;i<n;i++){
	        dic1[pat[i]-'a']++;
	    }
	    int cnt = 0;
	    vector<int> dic2(26,0);
	    for(int i=0;i<txt.size();i++){
	        if(i<n){
	            dic2[txt[i]-'a']++;
	        }
	        else{
	            dic2[txt[i-n]-'a']--;
	            dic2[txt[i]-'a']++;
	        }
	        if(comp(dic1,dic2)){
	                cnt++;
	         }
	    }
	    return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
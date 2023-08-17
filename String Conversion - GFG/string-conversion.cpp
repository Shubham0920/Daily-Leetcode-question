//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	bool solve(int i,int j,string s,string t){
	    if(j == t.size()){
	        if(s.size() == i){
	            return 1;
	        }
	        else{
	            for(int k=i;k<s.size();k++){
	                if(s[k]>=97 && s[k]<=122){
            	        continue;
            	    }
            	    else{
            	        return 0;
            	    }
                }
                return 1;
	        }
	    }
	    if(i == s.size()){
	        if(j == t.size())return 1;
	        else return 0;
	    }
	    if(t[j]>=97 && t[j]<=122) {
	        return 0;
	    }
	    if(s[i] == t[j] ){
	        return solve(i+1,j+1,s,t);
	    }
	    else if(s[i]-32 == t[j]){
	        return solve(i+1,j,s,t) || solve(i+1,j+1,s,t);
	    }
	    else if(s[i]>=97 && s[i]<=122){
	        return solve(i+1,j,s,t);
	    }
	    else{
	        return false;
	    }
	}
	int stringConversion(string X, string Y)
	{
	    // Your code goes here
	    return solve(0,0,X,Y);
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
   		string s1, s2;
   		cin >> s1 >> s2;

   		Solution ob;

   		cout << ob.stringConversion(s1, s2) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
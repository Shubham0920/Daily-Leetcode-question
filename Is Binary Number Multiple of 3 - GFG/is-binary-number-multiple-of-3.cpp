// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int even =0;
	    int odd = 0;
	    int n = s.length();
	    if(s.length() == 0){
	        return 0;
	    }
	    if(s.length() == 1 && s[0] == '0' ){
	        return 1;
	    }
	    if(s.length() == 1 && s[0] == '1' ){
	        return 0;
	    }
	    for(int i=n-1;i>=0;i--){
	        if(i%2 == 0 && s[i] == '1'){
	            even++;
	        }
	        if(i%2 != 0 && s[i] == '1'){
	            odd++;
	        }
	    }
	    if((odd-even)%3 == 0){
	        return 1;
	    }
	    else{
	        return 0;
	    }
	}

};

// { Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}

  // } Driver Code Ends
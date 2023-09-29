//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
     string rremove(string s){
        // code here
        
        string temp="";
        bool flag = false;
        
        for(int i = 0; i < s.length() ; i++){
            if(s[i] == s[i+1]){
                flag = true;
                while(s[i] == s[i+1]){
                    i++;
                }
            }
            
            else{
                temp.push_back(s[i]);
            }
        }
        
        //base condition
        if(!flag) return temp;
        
        return rremove(temp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends
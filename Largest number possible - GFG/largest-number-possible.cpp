//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int s){
        // code here
         string str="";
        if(s>n*9 ||(s==0 && n!=1))
        return "-1";
        while(n--)
        {
            if(s>9)
            {
                str+='9';
                s-=9;
            }
            else
            {
                str+=to_string(s);
                s=0;
            }
        }
        return str;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
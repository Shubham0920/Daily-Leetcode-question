//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string> vec;
        string s = "";
        for(int i=0;i<S.length();i++){
            if(S[i] != '.'){
                s+= S[i];
            }
            else{
                vec.push_back(s);
                s ="";
            }
        }
        vec.push_back(s);
        reverse(vec.begin(),vec.end());
        string ans="";
        for(int i=0;i<vec.size();i++){
            ans+=vec[i];
            if(i!=vec.size()-1)
            ans+=".";
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
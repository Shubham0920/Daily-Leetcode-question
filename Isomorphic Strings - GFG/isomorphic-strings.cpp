//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        if(str1.size() != str2.size())return 0;
        // Your code here
        map<char,char> m1;
        for(int i=0;i<str1.size();i++){
            if(m1.find(str1[i]) != m1.end()){
                if(m1[str1[i]]!= str2[i])return 0;
            }
            else{
                m1[str1[i]] = str2[i];
            }
        }
        map<char,char> m2;
        for(int i=0;i<str2.size();i++){
            if(m2.find(str2[i]) != m2.end()){
                if(m2[str2[i]]!= str1[i])return 0;
            }
            else{
                m2[str2[i]] = str1[i];
            }
        }
        return 1;
        
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
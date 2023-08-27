//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        vector<string>v;
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int mi=INT_MIN;
        string s;
        for(auto it:m){
            if(it.second>mi) {
                mi=it.second;
                 s=it.first;
            }
        }
        m[s]=0;
        if(m.size()==1) return "";
        mi=0;
        for(auto it:m){
            if(it.second>mi) {
                mi=it.second;
                 s=it.first;
            }
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
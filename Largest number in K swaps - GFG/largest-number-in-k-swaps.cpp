//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{   
    
    public:
    string maxi = "";
    //Function to find the largest number after k swaps.
    void find(string s,int k,int idx){
        if(s>maxi){
            maxi = s;
        }
        if(k==0)return;
        char maxm = s[idx];
        for(int j=idx+1;j<s.size();j++){
            if(s[j]>maxm){
                maxm = s[j];
            }
        }
        if(maxm != s[idx]){
            k--;
        }
        
        for(int j=idx;j<s.size();j++){
            if(s[j] == maxm){
                swap(s[idx],s[j]);
                find(s,k,idx+1);
                swap(s[idx],s[j]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       find(ans,k,0);
       return maxi;
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
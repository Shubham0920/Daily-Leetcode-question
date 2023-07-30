//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// return a string formed by compressing string s
// do not print anything

class Solution{
    public:
  // Your code goes here
        string compress(string s)
    {
        // Your code goes here
        int n=s.size();
        vector<int> v(n);
        
        int p=0;
        for(int j=1; j<n; j++)
        {
            while(p!=0 && s[p]!=s[j])
                p=v[p-1];
            
            if(s[p]==s[j])
            {
                v[j]=p+1;
                p+=1;
            }
        }
        string st="";
        int i=s.size();
        while(i)
        {
            if(i%2==1)
            {
                st.push_back(s[i-1]);
                i-=1;
            }
            else
            {
                if(v[i-1]>=i/2)
                {
                    if(i%(2*(i-v[i-1]))==0)
                    {
                        st.push_back('*');
                        i/=2;
                    }
                    else
                    {
                        st.push_back(s[i-1]);
                        i-=1;
                    }
                }
                else
                {
                    st.push_back(s[i-1]);
                    i-=1;
                }
            }
        }
        reverse(st.begin(), st.end());
        return st;
    }
    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<< obj.compress(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends
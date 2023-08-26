//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &mat, int r, int c){
            // code here  
            int p = (r*c+1)/2;
            int l = 1;
            int h = 1e9;
            while(l<h){
                int mid  = l + (h-l)/2;
                int k = 0;
                for(int i=0;i<r;i++){
                    k += upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
                }
                
                if(k<p){
                    l = mid+1;
                }
                else{
                    h = mid;
                }
                
            }
            return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends
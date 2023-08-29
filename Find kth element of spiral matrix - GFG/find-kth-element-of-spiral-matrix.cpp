//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int matrix[MAX][MAX],int r,int c,int k)
    {
 		// Your code goes here.
 		int i = 0;
        int j = 0;
        vector<int> ans;
        int x = r*c;
        int p = 0;
        int q = -1;
        char dir = 'r';
        while(x>0){
            if(dir == 'r'){
                if(j == c){
                    c--;
                    dir = 'd';
                    j--;
                    i++;
                }
                else{
                    ans.push_back(matrix[i][j]);
                    x--;
                    j++;
                }
            }
            else if(dir == 'd'){
                if(i==r){
                    r--;
                    dir = 'l';
                    i--;
                    j--;
                }
                else{
                    ans.push_back(matrix[i][j]);
                    x--;
                    i++;
                }
            }
            else if(dir == 'l'){
                if(j == q){
                    q++;
                    dir = 'u';
                    j++;
                    i--;
                }
                else{
                    ans.push_back(matrix[i][j]);
                    j--;
                    x--;
                }
            }
            else if(dir == 'u'){
                if(i == p){
                    p++;
                    i++;
                    j++;
                    dir = 'r';
                }
                else{
                    ans.push_back(matrix[i][j]);
                    x--;
                    i--;
                }
            }
            
        }
        return ans[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
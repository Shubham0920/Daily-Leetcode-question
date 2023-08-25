//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
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
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
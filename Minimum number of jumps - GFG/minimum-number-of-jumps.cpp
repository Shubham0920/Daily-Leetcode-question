//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(arr[0] == 0)return -1;
        // Your code here
        int curr = 0;
        int fat = 0;
        int jump= 0;
        for(int i=0;i<n;i++){\
            if(fat<i)return -1;
            fat = max(fat,arr[i]+i);
            if(i == curr){
                curr = fat;
                jump++;
                if(fat >= n-1)return jump;
            }
            
        }
        return jump-1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
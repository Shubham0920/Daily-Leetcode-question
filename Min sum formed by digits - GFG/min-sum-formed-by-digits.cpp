//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        sort(arr,arr+n);
        int p = 0;
        if(arr[0] == 0){
            p++;
        }
        long long num1=0,num2=0;
        for(int i=p;i<n;i+=2){
            num1 = num1*10+arr[i];
        }
        for(int j = p+1;j<n;j+=2){
            num2 = num2*10+arr[j];
        }
        // cout<<num1<<" "<<num2;
        return num1+num2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
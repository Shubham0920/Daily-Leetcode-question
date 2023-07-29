//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {
    
    int t;
    cin>> t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout << save_gotham(arr, n) << endl;
    }
    
	return 0;
}
// } Driver Code Ends


int save_gotham(int arr[], int n)
{
    // Complete the function
        // On-right
        vector<int> right(n);
        stack<int> st2;
        for(int i=n-1;i>=0;i--)
        {
            while(st2.size() && st2.top()<=arr[i])
                st2.pop();
            if(st2.size())
               right[i]=st2.top();
            else
               right[i]=0; 
            st2.push(arr[i]);   
        }
        //final
        int sum = 0;
        for(auto x:right){
            sum+=x;
        }
        
        return sum;
}
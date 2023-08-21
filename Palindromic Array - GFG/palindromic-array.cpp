//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    bool check(string arr,int n){
        int i=0;
    	int j=n-1;
    	while(i<j){
    	    if(arr[i]!=arr[j]){
    	        return 0;
    	    }
    	    else{
    	        i++;
    	        j--;
    	    }
    	}
    	return 1;
    }
    int PalinArray(int a[], int n){
        for(int i=0;i<n;i++){
            string s = to_string(a[i]);
            // cout<<s<<" "<<check(s,s.size())<<endl;
            if(check(s,s.size()) == 0)return 0;
        }
        return 1;
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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends
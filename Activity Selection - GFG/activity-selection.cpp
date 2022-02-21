// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    struct comp{
       bool operator()(pair<int,int> a, pair<int,int> b){
           if(a.second < b.second) return (true);
           else if(a.second > b.second) return (false);
           return a.first < b.first;
       }
   };
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; i++)
           v[i] = {start[i],end[i]};
       
        sort(v.begin(),v.end(),comp());
        
        int cnt=0;
        int s = v[0].first;
        int e = v[0].second;
        cnt++;
        for(int i=1;i<start.size();i++){
            if(v[i].first>e){
                cnt++;
                e = v[i].second;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
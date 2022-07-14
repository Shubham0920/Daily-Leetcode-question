// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int> ans;
    
    void made(vector<int>& nums,int start,int end){
        if(start>end){
            return;
        }
        // int mid;
        int mid = start+(end-start)/2;
        ans.push_back(nums[mid]);
        made(nums,start,mid-1);
        made(nums,mid+1,end);
        return;
    }
    
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        int start = 0;
        int end = nums.size()-1;
        made(nums,start,end);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends
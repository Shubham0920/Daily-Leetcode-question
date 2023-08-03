//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string b, string e, vector<string>& wordList) {
        // Code here
        set<string> se;
        for(auto x:wordList){
            se.insert(x);
        }
        queue<pair<string,int>> q;
        if(se.count(e) == 0)return 0;
        
        unordered_map<string,bool> vis;
        q.push({b,0});
        vis[b] = 1;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            string s = t.first;
            int dist = t.second;
            // cout<<s<<endl;
            
            if(s == e)return dist + 1;
            
            for(int i=0;i<s.size();i++){
                for(char c = 'a';c<='z';c++){
                    string str = s;
                    str[i] = c;
                    // cout<<str<<endl;
                    if(se.find(str)!= se.end() && vis[str] == 0){
                        // cout<<str<<endl;
                        q.push({str,dist+1});
                        vis[str] = 1;
                    }
                }
            }
        }
        return 0;
        
        // int n = b.size();
        // string tot = "abcdefghijklmnopqrstuvwxyz";
        // unordered_set<string> set;
        // unordered_map<string,bool> vis;
        
        // for(auto &i:w){
        //     set.insert(i);
        // }
        // if(set.count(e)== 0)return 0;
        
        // queue<pair<string,int>> q;
        // q.push({b,0});
        // vis[b] = true;
        
        // while(q.size()){
        //     auto it = q.front();
        //     q.pop();
        //     string s = it.first;
        //     int dis = it.second;
        //     if(s == e) return dis+1;
            
        //     for(int i=0;i<n;i++){
        //         for(int j=0;j<tot.length();j++){
        //             string ao = s;
        //             ao[i] = tot[j];
        //             if(set.count(ao)!=0 && vis[ao] != true){
        //                 q.push({ao,dis+1});
        //                 vis[ao] = true;
        //             }
        //         }
        //     }
        // }
        // return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
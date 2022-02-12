class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        int n = b.size();
        string tot = "abcdefghijklmnopqrstuvwxyz";
        unordered_set<string> set;
        unordered_map<string,bool> vis;
        
        for(auto &i:w){
            set.insert(i);
        }
        if(set.count(e)== 0)return 0;
        
        queue<pair<string,int>> q;
        q.push({b,0});
        vis[b] = true;
        
        while(q.size()){
            auto it = q.front();
            q.pop();
            string s = it.first;
            int dis = it.second;
            if(s == e) return dis+1;
            
            for(int i=0;i<n;i++){
                for(int j=0;j<tot.length();j++){
                    string ao = s;
                    ao[i] = tot[j];
                    if(set.count(ao)!=0 && vis[ao] != true){
                        q.push({ao,dis+1});
                        vis[ao] = true;
                    }
                }
            }
        }
        return 0;
    }
};
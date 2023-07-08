class Solution {
public:
    int small(string s){
        char c='z'+1;
        for(int i=0;i<s.size();i++){
            if(s[i]<c){
                c = s[i];
            }
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == c){
                cnt++;
            }
        }
        return cnt;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> q,w;
        for(int i=0;i<queries.size();i++){
            q.push_back(small(queries[i]));
        }
        for(int i=0;i<words.size();i++){
            w.push_back(small(words[i]));
        }
        sort(w.begin(),w.end());
        vector<int> ans;
        for(int i=0;i<q.size();i++){
            int k = q[i];
            cout<<k<<" ";
            int t = upper_bound(w.begin(),w.end(),k)-w.begin();
            ans.push_back(w.size()-t);
        }
        return ans;
    }
};
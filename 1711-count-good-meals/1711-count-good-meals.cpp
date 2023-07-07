class Solution {
public:
    int mod = 1000000007;
    int countPairs(vector<int>& d) {
        int ans=0;
        map<int,int> m;
        vector<int> p;
        for(int i=0;i<=21;i++){
            p.push_back(pow(2,i));
        }
        for(auto x:d){
            m[x]++;
        }
        for(int i=0;i<d.size();i++){
            long long cnt = 0;
            for(int j=0;j<p.size();j++){
                if(m.find(p[j]-d[i])!=m.end()){
                    cnt+=m[p[j]-d[i]];
                    if(p[j]-d[i]==d[i]){
                        cnt--;
                    }
                }
                
            }
            m[d[i]]--;
            ans = (ans%mod+cnt%mod)%mod;
        }
        return ans;
    }
};
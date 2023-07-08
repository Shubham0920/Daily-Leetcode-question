class MapSum {
public:
    map<string,int> m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string p) {
        int s = 0;
        int n = p.size();
        for(auto x:m){
            string st = x.first.substr(0,n);
            if(p == st)s+=x.second;
        }
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
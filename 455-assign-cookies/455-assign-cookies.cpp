class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0 || g.size() == 0){
            return 0;
        }
        sort(s.begin(),s.end(),greater<int>());
        sort(g.begin(),g.end(),greater<int>());
        int count=0;
        
        int j = 0;
        int max = s[j];
        
        for(int i=0;i<g.size();i++){
            if(g[i] <=max){
                count++;
                j++;
                if(j <s.size()){
                max = s[j];}
                else{
                    break;
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = INT_MIN;
        for(int i=0;i<strs.size();i++){
            bool flag = false;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]>='a' && strs[i][j]<='z'){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ans = max(ans,(int)strs[i].size());
            }
            else{
                ans = max(ans,stoi(strs[i]));
            }
        }
        return ans;
    }
};
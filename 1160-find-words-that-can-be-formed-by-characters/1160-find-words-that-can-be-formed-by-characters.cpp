class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> map;
        for(int i=0;i<chars.length();i++){
            map[chars[i]]++;
        }
        int ans = 0;
        for(int i=0;i<words.size();i++){
            unordered_map<char,int> map2;
            for(int j=0;j<words[i].size();j++){
                map2[words[i][j]]++;
            }
            bool flag = true;
            for(auto x:map2){
                if(map[x.first]< map2[x.first]){
                    flag = false;
                }
            }
            if(flag){
                ans += words[i].length();
            }
        }
        return ans;
    }
};
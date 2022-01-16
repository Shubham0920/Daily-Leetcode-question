class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int i = 0;
        int n = s.length();
        char t;
        while(i < n){
            if(s[i] == s[i+1]){
                t = s[i];
                ans+=t;
                ans+=t; 
                i = i+2;
                while(s[i] == t){
                    i++;
                }
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> ans;
    void allpermutation(string s,int i,string buf){
        if(i == s.length()){
            ans.push_back(buf);
            return ;
        }
        buf += s[i];
        allpermutation(s, i+1,buf);
        buf = buf.substr(0,i);
        
        
        if(s[i] >=65 && s[i] <=90){
            buf += s[i]+32;
            allpermutation(s, i+1,buf);
        }
        else{
            if(s[i] >=97 && s[i] <=122){
                buf += s[i] -32;
                allpermutation(s, i+1,buf);
            }
            else{
                buf += s[i];
            }
        }
        
        
    }
    vector<string> letterCasePermutation(string s) {
        string buf = "";
        allpermutation(s,0,buf);
        return ans;
    }
};
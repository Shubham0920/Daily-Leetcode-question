class Solution {
public:
    bool checkString(string s) {
        int a=-1;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'a'){
                a = i;
            }
        }
        int b=-1;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'b'){
                b = i;
                break;
            }
        }
        if(b == -1){
            return true;
        }
        return a<b;
    }
};
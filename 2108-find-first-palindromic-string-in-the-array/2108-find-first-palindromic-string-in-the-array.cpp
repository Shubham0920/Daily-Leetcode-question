class Solution {
public:
    bool ispalindrom(string s, int start,int end){
        while(start<=end){
            if(s[start++] != s[--end]){
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(ispalindrom(words[i],0,words[i].size())){
                return words[i];
            }
        }
        return "";
    }
};
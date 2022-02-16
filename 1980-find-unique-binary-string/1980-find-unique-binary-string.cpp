class Solution {
public:
    string ans;
    bool flag;
    
    void findstring(vector<string>& nums,int i,int n,string s){
        if(i == n){
            return;
        }
        if(s[i] == '0') s[i] = '1';
        else{ s[i] = '0';}
        auto it = find(nums.begin(), nums.end(), s);
        if(it == nums.end()){
            ans = s;
            flag = true;
            return;
        }
        else{
            findstring(nums,i+1,n,s);
        }
        // if(s[i] == '1') s[i] = '0';
        // else{ s[i] = '1';}
        // findstring(nums,i+1,n,s);
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(int i=0;i<nums.size();i++){
            string s = nums[i];
            int n = s.length();
            findstring(nums,0,n,s);
            if(flag) break;
        }
        return ans;
    }
};
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> s;
        for(int i=0;i<arr.size();i++){
            s[arr[i]*2]++;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0){
                if(s[arr[i]]>1){
                    return 1;
                }
                else{
                    continue;
                }
            }
            if(s[arr[i]]>0){
                return true;
            }
        }
        return false;
    }
};
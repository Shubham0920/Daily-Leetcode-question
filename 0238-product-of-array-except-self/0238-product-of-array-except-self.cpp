class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long ans = 1;
        bool flag = false,flag2=false;;
        for(auto x:nums){
            if(x==0 && flag == false){
                flag = true;
            }
            else if(x==0 && flag==true){
                flag2=true;
            }
            else{
                ans*=x;
            }
        }
        vector<int> p;
        for(int i=0;i<nums.size();i++){
            if(flag2){
                p.push_back(0);
            }
            else if(flag == true && nums[i]!=0){
                p.push_back(0);
            }
            else if(flag && nums[i] == 0){
                p.push_back(ans);
            }
            else{
                p.push_back(ans/nums[i]);
            }
        }
        return p;
    }
};
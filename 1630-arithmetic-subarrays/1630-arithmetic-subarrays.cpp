class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
      vector<bool> ans;
      int m = l.size();
        for(int i=0;i<m;i++){
            int s = l[i], e=r[i];
            vector<int> b = nums;
            sort(b.begin()+s,b.begin()+e+1);
            bool flag = true;
            for(int j=s;j<e;j++){
               // cout<<b[j]<<" "; 
                if((b[j+1]-b[j]) != (b[s+1]-b[s])){
                    flag = false;
                    break;
                }
            }
            cout<<endl;
            ans.push_back(flag);
        }
        return ans;
    }
};
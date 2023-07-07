class FindSumPairs {
public:
    map<int,int> m;
    vector<int> num1,num2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1=nums1;
        num2=nums2;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        m[num2[index]]--;
        m[num2[index]+val]++;
        num2[index]+=val;
    }
    
    int count(int tot) {
        int ans=0;
        for(int i=0;i<num1.size();i++){
            if(m.find(tot-num1[i])!=m.end()){
                ans+=m[tot-num1[i]];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=t.size()-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(0);
            }
            else if(!st.empty() && st.top().first>t[i]){
                ans.push_back(st.top().second-i);
            }
            else if(!st.empty() && st.top().first<=t[i]){
                while(!st.empty() && st.top().first<=t[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(st.top().second-i);
                }
            }
            st.push({t[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result=INT_MIN;
        int l=0,r=height.size()-1;
        while(l<r){
            int currarea = min(height[l],height[r])*(r-l);
            result = max(currarea,result);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return result;
    }
};
class Solution {
private:
    bool backtracking(vector<int>& matchsticks, vector<int>& sides, int i, int& n, int len){
        if(i==n)return true; //base case
        for(int j=0;j<4;j++){
            if(sides[j]+matchsticks[i]<=len){
                sides[j]+=matchsticks[i];//checking whether it can be added in the 1st one
                if(backtracking(matchsticks, sides, i+1, n, len))return true;
                sides[j]-=matchsticks[i]; //backtracking
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if(n<=3)return false;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); //descending order
        int sum=0;
        sum=accumulate(matchsticks.begin(), matchsticks.end(), 0); //finding sum for finding avg
        int avg=sum/4;
        if(sum/4 != avg){ //if 4 sides can't be made
            return false;
        }
        vector<int>sides(4, 0);
        
        return backtracking(matchsticks, sides, 0, n, avg); 
    }
};
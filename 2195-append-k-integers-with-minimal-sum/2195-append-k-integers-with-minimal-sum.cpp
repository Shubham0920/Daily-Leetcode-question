class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        long long first=1,sum=0;
        for(auto x:m){
            long long l=first;
            long long r=x.first;
            
            if(k>(r-l)){
                k -= (r-l);
            }
            else {
                break;
            }
            
            sum+= r*(r-1)/2-(l)*(l-1)/2;
            first = x.first+1;
        }
        
        long long l = first;
        long long r = first+k;
        sum += r*(r-1)/2-(l)*(l-1)/2;
        return sum;        
    }
};
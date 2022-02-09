class Solution {
public:
    int minimumSum(int arr) {
        vector<int> num;
        while(arr>0){
            int x = arr%10;
            arr = arr/10;
            num.push_back(x);
        }
        sort(num.begin(),num.end());
        return num[0]*10+num[1]*10+num[2]+num[3];
        int top = 0;
        for(int i=0;i<4;i++){
            cout<<num[i];
            if(num[i] ==0){
                top++;
            }
        }
        if(top==0){
            return num[0]*10 + num[1] + num[2]*10 + num[3];
        }
        if(top==1){
            return num[1]*10 + num[2] + num[3];
        }
        if(top==2){
            return num[2] + num[3];
        }
        else{
            return num[3];
        }
        
    }
};
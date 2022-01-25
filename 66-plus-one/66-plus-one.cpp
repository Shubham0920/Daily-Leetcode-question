class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1] != 9){
            digits[digits.size()-1] = digits[digits.size()-1] + 1;
            return digits;
        }
        int count = 1;
        do{
            digits[digits.size()-count] = 0;
            count++;
            if((digits.size()>=count) && (digits[digits.size()-count]!=9)){
                digits[digits.size()-count]++;
                break;
            }else if(digits.size()<count){
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }while(digits[digits.size()-count]==9);
        return digits;
    }
};
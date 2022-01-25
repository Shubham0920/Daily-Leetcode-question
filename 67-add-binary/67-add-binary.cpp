class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i = a.length()-1;
        int j = b.length()-1;
        
        int res = 0;
        while(i>=0 && j>=0){
            if(a[i] == '1' && b[j] == '1'){
                if (res == 1){
                    ans += "1";
                    res = 1;
                    
                }
                else{
                    ans += '0';
                    res  = 1;
                }
                
            }
            
            if(a[i] == '1' && b[j] == '0' || a[i] == '0' && b[j] == '1'){
                if (res == 1){
                    ans += '0';
                }
                else{
                    ans += '1';
                    res  = 0;
                }
            }
            if(a[i] == '0' && b[j] == '0'){
                if (res == 1){
                    ans += '1';
                    res = 0;
                }
                else{
                    ans += '0';
                    res  = 0;
                }
                
            }
            i--;j--;
        }
        while(i>=0){
            if (res == 1){
                if(a[i] == '1'){
                    ans+="0";
                    res = 1;
                }
                else{
                    ans += "1";
                    res = 0;
                }
            }
            else{
                ans += a[i];
            }
            i--;
        }
        while(j>=0){
            if (res == 1){
                cout<<b[j];
                if(b[j] == '1'){
                    ans+="0";
                    res = 1;
                    cout<<ans;
                }
                else{
                    ans += "1";
                    res = 0;
                }
            }
            else{
                ans += b[j];
            }
            j--;
        }
        if (res == 1){
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
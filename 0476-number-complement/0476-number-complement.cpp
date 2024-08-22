class Solution {
public:
    string toBinary(int num){
        if(num == 0){
            return "0";
        }
        
        string bin = "";
        while(num > 0){
            bin = to_string(num % 2) + bin;
            num /= 2;
        }
        
        return bin;
    }
    
    int toDecimal(string bin){
        int ret = 0;
        int len = bin.length();
        
        for(int i = 0; i < len; ++i){
            if(bin[len - 1 - i] == '1'){
                ret += pow(2, i);
            }
        }
        
        return ret;
    }
    
    int findComplement(int num) {
        string bin = toBinary(num);
        string complement = "";
        
        for(char &c : bin){
            if(c == '1'){
                complement += "0";
            }else{
                complement += "1";
            }
        }
        
        int ans = toDecimal(complement);
        
        return ans;
    }
};
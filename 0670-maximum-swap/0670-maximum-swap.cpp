class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        
        int max_idx = -1, max_val = -1;
        int r_idx = -1, l_idx = -1;
        
        for(int i = s.length() - 1; i >= 0; --i){
            if(s[i] > max_val){
                max_val = s[i];
                max_idx = i;
                continue;
            }
            
            if(s[i] < max_val){
                l_idx = i;
                r_idx = max_idx;
            }
        }
        
        if(l_idx == -1){
            return num;
        }
        
        swap(s[r_idx], s[l_idx]);
        
        return stoi(s);
    }
};
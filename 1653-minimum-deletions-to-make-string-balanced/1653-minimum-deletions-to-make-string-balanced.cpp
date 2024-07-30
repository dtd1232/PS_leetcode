class Solution {
public:
    int minimumDeletions(string s) {
        int cnt_a = 0;
        int cnt_b = 0;
        int n = s.length();
        
        for(int i = 0; i < n; ++i){
            if(s[i] == 'a'){
                cnt_a++;
            }
        }
        
        int ans = n;
        
        for(int i = 0; i < n; ++i){
            if(s[i] == 'a'){
                cnt_a--;
            }
            ans = min(ans, cnt_a + cnt_b);
            if(s[i] == 'b'){
                cnt_b++;
            }
        }
        
        return ans;
    }
};
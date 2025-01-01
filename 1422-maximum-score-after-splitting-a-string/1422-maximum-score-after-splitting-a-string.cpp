class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int totalOnes = 0;
        int zeroCnt = 0;
        int oneCnt = 0;
        int best = INT_MIN;

        for(char ch : s){
            if(ch == '1'){
                totalOnes++;
            }
        }

        for(int i = 0; i < s.length() - 1; ++i){
            if(s[i] == '0'){
                zeroCnt++;
            }else{
                oneCnt++;
            }

            int curScore = zeroCnt + (totalOnes - oneCnt);
            best = max(best, curScore);
        }

        return best;
    }
};
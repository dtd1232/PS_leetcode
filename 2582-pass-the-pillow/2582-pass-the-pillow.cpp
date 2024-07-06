class Solution {
private:
    int direction = 1;
    int cnt = 2;
public:
    int passThePillow(int n, int time) {
        for(int i = 1; i < time; ++i){
            if(cnt == n || cnt == 1){
                direction *= -1;
                cnt += direction;
            }else{
                cnt += direction;
            }
        }
        
        return cnt;
    }
};
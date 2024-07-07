class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int emptyBottle = 0;
        
        while(true){
            
            if((numBottles + emptyBottle) < numExchange){
                ans += numBottles;
                break;
            }
            
            ans += numBottles;
            emptyBottle += numBottles;
            numBottles = emptyBottle / numExchange;
            emptyBottle = emptyBottle % numExchange;
        }
        
        return ans;
    }
};
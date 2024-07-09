class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitTime = customers[0][1];
        int finishedTime = customers[0][0] + customers[0][1];
        
        for(int i = 1; i < customers.size(); ++i){
            int arrive = customers[i][0];
            
            int startCook = max(arrive, finishedTime);
            int endCook = startCook + customers[i][1];
            finishedTime = endCook;
            waitTime += endCook - arrive;
        }
        
        return waitTime / customers.size();
    }
};
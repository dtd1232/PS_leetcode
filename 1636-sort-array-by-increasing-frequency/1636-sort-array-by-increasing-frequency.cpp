class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        if (a.second == b.second) {
            return a.first > b.first;
        } else {
            return a.second < b.second;
        }
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> m;
        vector<pair<int, int>> v;
        vector<int> answer;
        
        for(int i = 0; i < nums.size(); ++i){
            m[nums[i]]++;
        }
        
        for(auto it : m){
            v.push_back({it.first, it.second});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        for(auto it : v){
            for(int i = 0; i < it.second; ++i){
                answer.push_back(it.first);
            }
        }
        
        return answer;
    }
};
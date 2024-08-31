class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;
        
        for(int i = 0; i < nums.size(); ++i){
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end());
        
        int l = 0, r = nums.size() - 1;
        int sum = 0;
        
        while(1){
            sum = v[l].first + v[r].first;
            
            if(sum == target){
                break;
            }else if(sum > target){
                r--;
            }else{
                l++;
            }
        }
        
        return {v[l].second, v[r].second};
    }
};
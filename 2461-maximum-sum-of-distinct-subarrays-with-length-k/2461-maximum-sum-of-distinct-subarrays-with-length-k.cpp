class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        map<int, int> m;
        
        for(int i = 0; i < k; ++i){
            sum += nums[i];
            m[nums[i]]++;
        }
        
        if(m.size() == k){
            ans = sum;
        }
        
        for(int i = k; i < nums.size(); ++i){
            m[nums[i]]++;
            m[nums[i - k]]--;
            if(m[nums[i - k]] == 0){
                m.erase(nums[i - k]);
            }
            sum += nums[i];
            sum -= nums[i - k];
            
            if(m.size() == k){
                ans = max(ans, sum);
            }
        }
        
        return ans;
    }
};
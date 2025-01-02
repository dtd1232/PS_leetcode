class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> preSum(words.size() + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for(int i = 0; i < words.size(); ++i){
            preSum[i + 1] = preSum[i];
            if(vowels.count(words[i].front()) && vowels.count(words[i].back())){
                preSum[i + 1]++;
            }
        }

        for(auto& query : queries){
            int l = query[0], r = query[1];
            ans.push_back(preSum[++r] - preSum[l]);
        }

        return ans;
    }
};
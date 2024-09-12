class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char, int> allowed_map;
        int ans = 0;
        
        for(int i = 0; i < allowed.length(); ++i){
            allowed_map[allowed[i]] = 1;
        }
        
        for(int i = 0; i < words.size(); ++i){
            int isAllowed = 1;
            for(int j = 0; j < words[i].length(); ++j){
                if(allowed_map[words[i][j]] != 1){
                    isAllowed = 0;
                    break;
                }
            }
            ans += isAllowed;
        }
        
        return ans;
    }
};
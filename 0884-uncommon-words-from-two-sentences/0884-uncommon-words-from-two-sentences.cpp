class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        map<string, int> m;
        string tmp_str = "";
        
        for(int i = 0; i < s1.length(); ++i){
            if(s1[i] != ' '){
                tmp_str += s1[i];
            }else{
                m[tmp_str]++;
                tmp_str = "";
            }
        }
        
        m[tmp_str]++;
        tmp_str = "";
        
        for(int i = 0; i < s2.length(); ++i){
            if(s2[i] != ' '){
                tmp_str += s2[i];
            }else{
                m[tmp_str]++;
                tmp_str = "";
            }
        }
        
        m[tmp_str]++;
        
        for(auto i : m){
            if(i.second == 1){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> m;
        set<int> s;
        vector<int> ans;
        
        for(int i = 0; i < arr.size(); ++i){
            s.insert(arr[i]);
        }
        
        int cnt = 1;
        
        for(auto i : s){
            m[i] = cnt;
            cnt++;
        }
        
        for(int i = 0; i < arr.size(); ++i){
            ans.push_back(m[arr[i]]);
        }
        
        return ans;
    }
};
class Solution {
private:
    map<int, int> m1;
    map<int, int> m2;
    
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        
        for(int i = 0; i < nums1.size(); ++i){
            if(m1.find(nums1[i]) == m1.end()){
                m1[nums1[i]] = 1;
            }else{
                m1[nums1[i]]++;
            }
        }
        
        for(int i = 0; i < nums2.size(); ++i){
            if(m2.find(nums2[i]) == m2.end()){
                m2[nums2[i]] = 1;
            }else{
                m2[nums2[i]]++;
            }
        }
        
        for(auto iter : m1){
            if(m2.find(iter.first) != m2.end()){
                for(int i = 0; i < min(iter.second, m2[iter.first]); ++i){
                    answer.push_back(iter.first);
                }
            }
        }
        
        return answer;
    }
};
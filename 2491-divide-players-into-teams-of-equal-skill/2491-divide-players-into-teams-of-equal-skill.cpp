class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long answer = 0;
        
        if(skill.size() == 2){
            return skill[0] * skill[1];
        }
        
        sort(skill.begin(), skill.end());
        
        int l = 0, r = skill.size() - 1;
        int skill_sum = skill[l] + skill[r];
        answer = skill[l] * skill[r];
        
        l++, r--;
        
        while(l < r){
            if(skill[l] + skill[r] != skill_sum){
                return -1;
            }else{
                answer += skill[l] * skill[r];
            }
            l++, r--;
        }
        
        return answer;
    }
};
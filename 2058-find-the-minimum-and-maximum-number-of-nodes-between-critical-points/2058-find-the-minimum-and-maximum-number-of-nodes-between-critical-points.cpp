/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        vector<int> dist;
        int cnt = 0;
        int maxDist, minDist = 1000001;
        
        ListNode *cur = head->next;
        ListNode *nextNode = cur->next;
        ListNode *prev = head;
        
        while(nextNode != nullptr){
            if(cur->val < nextNode->val && cur->val < prev->val){
                dist.push_back(cnt);
            }
            if(cur->val > nextNode->val && cur->val > prev->val){
                dist.push_back(cnt);
            }
            
            nextNode = nextNode->next;
            cur = cur->next;
            prev = prev->next;
            cnt++;
        }
        
        if(dist.size() < 2){
            return {-1, -1};
        }
        
        
        for(int i = 1; i < dist.size(); ++i){
            minDist = min(minDist, dist[i] - dist[i - 1]);
        }
        
        maxDist = dist[dist.size() - 1] - dist[0];
        
        ans.push_back(minDist);
        ans.push_back(maxDist);
        
        return ans;
    }
};
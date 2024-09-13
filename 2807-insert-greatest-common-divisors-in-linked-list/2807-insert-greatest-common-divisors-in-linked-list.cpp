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
    int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        
        return a;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        
        if(head->next == nullptr){
            return cur;
        }
        
        while(true){
            if(cur->next == nullptr){
                break;
            }
            
            int temp = gcd(cur->val, cur->next->val);
            ListNode* node = new ListNode(temp);
            
            ListNode* nxt = cur->next;
            cur->next = node;
            node->next = nxt;
        
            cur = nxt;
        }
        
        return head;
    }
};
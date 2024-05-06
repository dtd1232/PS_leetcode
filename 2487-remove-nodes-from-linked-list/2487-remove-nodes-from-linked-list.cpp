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
    ListNode* removeNodes(ListNode* head) {
        stack<int> s1; 
        stack<int> s2;

        ListNode *cur;
        cur = head;
        while(true){
            s1.push(cur->val);
            cur = cur->next;
            if(cur == nullptr){
                break;
            }
        }

        s2.push(s1.top());
        s1.pop();

        while(!s1.empty()){
            if(s1.top() < s2.top()){
                s1.pop();
            }else{
                s2.push(s1.top());
                s1.pop();
            }
        }

        head = new ListNode(s2.top());
        cur = head;
        s2.pop();

        while(!s2.empty()){
            cur->next = new ListNode(s2.top());
            cur = cur->next;
            s2.pop();
        }

        return head;
    }
};
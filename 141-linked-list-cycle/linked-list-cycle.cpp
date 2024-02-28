/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast != nullptr){
            if(fast->next){
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow) return true;
            }
            else{
                fast = fast->next;
            }
        }
        return false;
    }
};
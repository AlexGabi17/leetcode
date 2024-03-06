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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* mid = head, *fast = head, *prev = nullptr;
        while(fast){
            if(fast->next){
                fast = fast->next->next;
                prev = mid;
                mid = mid->next;
            }
            else{
                fast = fast->next;
            }
        }
        
        if(prev)
            prev->next = mid->next; 
        else
            head = head->next;

        delete mid;
        return head;
    }
};
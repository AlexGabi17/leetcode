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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode* mid = head, *it = head, *prev = nullptr;
        while(it != nullptr){
            if(it->next){
                it = it->next->next;
                mid = mid->next;
            }
            else{
                it = it->next;
                mid = mid->next;
            }
        }

        /*if(!mid->next) return head->val == mid->val;*/

        ListNode* nxt = nullptr;
        prev = nullptr;
        while(mid != nullptr){
            nxt = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nxt;
        }
        
        ListNode* tail = prev;
        while(head != nullptr && tail != nullptr){
            if(head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }

        return true;
    }
};
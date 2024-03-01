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
    int pairSum(ListNode* head) {
        ListNode* mid = head, *fast = head;
        int max_ = INT_MIN;
        while(fast && fast->next){
            fast = fast->next->next;
            mid = mid->next;
        }
        // cout<<mid->val;

        ListNode* prev = nullptr;
        while(mid){
            ListNode* nxt = mid->next;
            mid->next = prev;
            prev = mid;
            mid = nxt;
        }
        // cout<<prev->val;

        while(head && prev){
            if(head->val + prev->val > max_) max_ = head->val + prev->val;
            head = head->next;
            prev = prev->next;
        }

        return max_;
    }
};
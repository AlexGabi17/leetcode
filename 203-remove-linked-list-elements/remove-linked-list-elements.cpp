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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* it = head, *prev = nullptr;
        while(it && it->val == val){
            ListNode* to_delete= it;
            it = it->next;
            delete to_delete;
        }
        ListNode* node = it;
        while(it){
            if(it->val == val){
                ListNode* to_delete = it;
                prev->next = it->next;
                it = it->next;
                delete to_delete;
            }
            else{
                prev = it;
                it = it->next;
            }
        }
        return node;
    }
};
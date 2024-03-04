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
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = head, *prev = nullptr;
        while(head){
            ListNode *node1 = head, *node2 = head->next, *nxt = nullptr;
            if(node2){
                nxt = node2->next;
            }
            else{
                head = nxt;
                continue;
            }
            node2->next = node1;
            node1->next = nxt;
            if(prev){
                prev->next = node2;
            }
            else{
                res = node2;
            }

            prev = node1;
            head = nxt;
        }
        return res;
    }
};
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int it = 0;
        ListNode* temp = list1;
        while(it != (a-1) && temp){
            it ++;
            temp = temp->next;
        }
        ListNode* begin = temp, *nxt = nullptr;
        temp = temp->next;

        while(it != b && temp){
            ListNode* to_delete = temp;
            temp = temp->next;
            it ++;
            delete to_delete;
        }

        begin->next = list2;
        ListNode* tail_2 = list2;
        
        while(tail_2->next){
            tail_2 = tail_2->next;
        }
        tail_2->next = temp;
        return list1;
    }
};
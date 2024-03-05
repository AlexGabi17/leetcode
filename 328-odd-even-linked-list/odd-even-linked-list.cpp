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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode* odd = head, *even = head->next, *begin_odd = odd, *begin_even = even, *temp = head;
        int i = 3;
        if(head->next){
            temp = temp->next->next;
        }
        
        while(temp){
            ListNode* nxt = temp->next;
            if(i%2 == 0){
                even->next = temp;
                even = even->next;
            }
            else{
                odd->next = temp;
                odd = odd->next;
            }
            i++;
            temp = nxt;
        }

        even->next = nullptr;
        odd->next = begin_even;
        return begin_odd;
        
    }
};
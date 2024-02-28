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
    int getDecimalValue(ListNode* head) {
        ListNode* it=head;
        int res = 0, binary = 1;
        it = it->next;
        while(it){
            binary *= 2;
            it = it->next;
        }
        cout<<binary;
        while(head){
            res += head->val * binary;
            if(binary == 1) binary --;
            else binary /= 2;
            head = head->next;
        }

        return res;
    }
};
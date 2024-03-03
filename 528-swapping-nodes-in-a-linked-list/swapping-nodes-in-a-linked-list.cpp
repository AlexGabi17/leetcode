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
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0, second_index, index;
        ListNode* temp = head, *first = nullptr, *second = nullptr;
        while(temp){
            length ++;
            if(length == k) first = temp;
            temp = temp->next;
        }
        second_index = length - k;
        temp = head;
        index = 0;
        while(temp){
            if(index == second_index){
                second = temp;
            }
            index ++;
            temp = temp->next;
        }
        int aux = first->val;
        first->val = second->val;
        second->val = aux;
        return head;
    }
};
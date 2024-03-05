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
    ListNode* reverse(ListNode* head){
        ListNode* nxt = nullptr, *prev = nullptr;
        while(head){
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1 = reverse(l1), *list2 = reverse(l2), *res = new ListNode(), *aux = res;
        int sum, r = 0;
        while(list1 && list2){
            sum = (list1->val + list2->val) + (r > 0);
            if(sum > 9){
                r = sum - 9;
                sum = sum - 10;
            }
            else{
                r = 0;
            }
            aux->next = new ListNode(sum);
            aux = aux->next;
            list1 = list1->next;
            list2 = list2->next;
        }
        while(list1){
            int sum = list1->val + (r > 0);
            if(sum > 9){
                r = sum - 9;
                sum = sum - 10;
            }
            else{
                r = 0;
            }
            aux->next = new ListNode(sum);
            aux = aux->next;
            list1 = list1->next;
        }
        while(list2){
            int sum = list2->val + (r > 0);
            if(sum > 9){
                r = sum - 9;
                sum = sum - 10;
            }
            else{
                r=0;
            }
            aux->next = new ListNode(sum);
            aux = aux->next;
            list2 = list2->next;
        }
        if(r > 0){
            aux->next = new ListNode(1);
        }
        return reverse(res->next);
    }
};
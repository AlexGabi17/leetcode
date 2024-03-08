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
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* node = new ListNode(-1);
        ListNode *temp = node;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if(list1) temp->next = list1;
        else temp->next = list2;

        return node->next;
    }
    ListNode* findMiddle(ListNode* head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
    ListNode* sortLL(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *middle = findMiddle(head);
        ListNode *right = middle->next;
        middle->next = nullptr;
        ListNode *left = head;
        
        left = sortLL(left);
        right = sortLL(right);

        return merge(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {

        return sortLL(head);

    }
};
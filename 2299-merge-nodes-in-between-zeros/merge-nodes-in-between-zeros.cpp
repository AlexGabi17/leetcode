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
    ListNode* mergeNodes(ListNode* head) {
       ListNode* temp = head;
       while(temp && temp->next){

           ListNode* it = temp->next;
           int count = 0;
           if(it->val != 0){
               count += it->val;
           }
           it = it->next;
            while(it && it->val != 0){
                count += it->val;
                ListNode* to_delete = it;
                it = it->next;
                delete to_delete;
            }
           
            temp = temp->next;
            temp->val = count;
            temp->next = it;
            temp = it;
       }
       ListNode* to_delete = nullptr, *prev = nullptr, *begin = head;
       to_delete = begin;
       begin = begin->next;
       delete to_delete;
       head = begin;

        while(head){
            if(head->val == 0){
                to_delete = head;
                prev->next = head->next;
                head = head->next;
                delete to_delete;
            }
            else{
                prev = head;
                head = head->next;
            }
        }

       return begin; 
    }
};
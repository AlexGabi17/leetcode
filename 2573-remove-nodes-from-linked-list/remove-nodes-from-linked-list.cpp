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
    ListNode* removeNodes(ListNode* head) {
        ListNode* rev = reverse(head);

        stack<int> stck;
        ListNode* temp = rev;
        while(temp){
            if(stck.empty()){
                stck.push(temp->val);
            }
            else{
                if(stck.top() <= temp->val){
                    stck.push(temp->val);
                }
            }
            temp = temp->next;
        }
        ListNode* new_head = new ListNode();
        temp = new_head;
        while(!stck.empty()){
            temp->next = new ListNode(stck.top());
            stck.pop();
            temp = temp->next;
        }
        return new_head->next;
    }
};
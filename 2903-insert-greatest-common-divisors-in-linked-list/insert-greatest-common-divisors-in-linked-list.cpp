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
    int gcd(int a, int b){
        int r;
        while(b != 0){
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;

        ListNode* temp = head;
        int val;
        while(temp){
            if(temp->next){
                ListNode* nxt = temp->next;
                val = gcd(temp->val, temp->next->val);
                ListNode* new_node = new ListNode(val);
                temp->next = new_node;
                new_node->next = nxt;
                temp = nxt;
            }
            else{
                break;
            }
        }
        return head;
    }
};
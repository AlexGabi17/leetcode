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
    int length = 0;
    ListNode* list = nullptr;
public:
    Solution(ListNode* head) {
        ListNode* temp = head;
        list = head;
        while(temp){
            this->length ++;
            temp = temp->next;
        }
        // cout<< length<<" ";
    }
    
    int getRandom() {
        int val = rand() % length, i=0;
        ListNode* temp = list;
        while(temp && i<val){
            temp = temp->next;
            i++;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
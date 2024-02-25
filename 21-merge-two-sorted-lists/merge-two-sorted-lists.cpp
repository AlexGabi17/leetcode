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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root, *tail;
        tail = new ListNode(-1);
        root = tail;
        while(list1 != nullptr && list2 != nullptr){
            
            //cout<<list1->val<<" "<<list2->val<<"\n";
            if(list1->val < list2->val){
                root->next =new ListNode(list1->val);
                list1 = list1->next;
            }
            else if(list1->val == list2->val){
                root->next = new ListNode(list1->val);
                root = root->next;
                root->next = new ListNode(list2->val);
                list1 = list1->next;
                list2 = list2->next;
            }
            else{
                root->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            //cout<<root->val<<"\n";
            root = root->next;
        }
        while(list1 != nullptr){
            root->next = new ListNode(list1->val);
            root = root->next;
            list1 = list1->next;
        }
        while(list2 != nullptr){
            root->next = new ListNode(list2->val);
            root = root->next;
            list2 = list2->next;
        }
        return tail->next; 
    }
};
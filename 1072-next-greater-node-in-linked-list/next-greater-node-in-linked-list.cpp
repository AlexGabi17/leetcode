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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, stck;
        for(ListNode* node = head; node; node = node->next){
            while(stck.size() && res[stck.back()] < node->val){
                res[stck.back()] = node->val;
                stck.pop_back();
            }
            stck.push_back(res.size());
            res.push_back(node->val);
        }
        for(int i: stck) res[i] = 0;
        return res;
    }
};
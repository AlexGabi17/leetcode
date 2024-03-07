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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> res = {-1, -1};
        int first_index_cp = -1, last_index_cp = -1, prev_index_cp = -1, i=0, min_ =  INT_MAX;
        ListNode* prev = nullptr;
        while(head){
            if(prev && head->next){
                // cout<<prev->val<<" "<<head->val<<" "<<head->next->val<<'\n';
                if((prev->val > head->val && head->val < head->next->val) || (prev->val < head->val && head->val > head->next->val)){
                    // cout<<"critical point: "<<head->val<<"\n";
                    if(first_index_cp == -1){
                        first_index_cp = i;
                    }
                    else{
                        prev_index_cp = last_index_cp;
                        last_index_cp = i;
                    }
                    if(prev_index_cp == -1 && last_index_cp != -1){
                        min_ = min(min_, last_index_cp - first_index_cp);
                    }
                    if(last_index_cp > 0 && prev_index_cp > 0){
                        min_ = min(min_, last_index_cp - prev_index_cp);
                    }
                }
            }
            prev = head;
            head = head->next;
            i ++;
        }
        // cout<<first_index_cp<<" "<<prev_index_cp<<" "<<last_index_cp<<'\n';
        res[0] = (min_ != INT_MAX) ? min_ : -1 ;
        if(last_index_cp != -1){
            res[1] = last_index_cp - first_index_cp;
        }
        return res;
    }
};
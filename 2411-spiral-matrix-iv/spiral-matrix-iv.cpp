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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        vector<int> d1 {0, 1, 0, -1};
        vector<int> d2 {1, 0, -1, 0};
        int i = 0, j = 0, direction = 0;
        while(head && res[i][j] == -1){
            res[i][j] = head->val;
            head = head->next;
            if (!(d1[direction] + i >=0 && d1[direction] + i < m && d2[direction] + j >=0 && d2[direction] + j < n && res[ d1[direction] + i ][ d2[direction] + j ] == -1)){
                direction ++;
                direction = direction % 4;
            }
            i = d1[direction] + i;
            j = d2[direction] + j;
        }
        return res;
    }
};
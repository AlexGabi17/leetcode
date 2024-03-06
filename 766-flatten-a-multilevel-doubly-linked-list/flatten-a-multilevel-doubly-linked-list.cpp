/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head, *nxt = nullptr, *aux = nullptr, *prev = nullptr;
        stack<Node*> stck;
        while(curr){
            cout<< curr->val<<" ";
            if(curr->child){
                stck.push(curr->next);
                //cout<<curr->val<<" ";
                if(curr->next){
                    curr->next->prev = nullptr;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;

            }
            prev = curr;
            curr = curr->next;
            if(curr == nullptr){
                while(!stck.empty() && stck.top() == nullptr){
                    stck.pop();
                }
                if(!stck.empty()){

                    curr = stck.top();
                    stck.pop();
                    prev->next = curr;
                    curr->prev = prev;


                }
                else{
                    break;
                }
            }

        }
        return head;
    }
};
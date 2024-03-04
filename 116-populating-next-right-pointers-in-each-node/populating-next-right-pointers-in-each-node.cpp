/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            if(temp && temp->left){
                temp->left->next = temp->right;
                if(temp->left->right){
                    temp->left->right->next = temp->right->left;
                }
                if(temp->right != nullptr && temp->next && temp->next->left){
                    temp->right->next = temp->next->left;
                }
                q.push(temp->left);
                q.push(temp->right);
            }

        }
        return root;
    }
};
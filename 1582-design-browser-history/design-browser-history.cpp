struct DoubleLinkedList{
    string val;
    DoubleLinkedList* prev, *next;
    DoubleLinkedList(string val = "", DoubleLinkedList *prev = nullptr, DoubleLinkedList* next = nullptr){
        this->val = val;
        this->prev = prev;
        this->next = next;
    }
};
class BrowserHistory {
    DoubleLinkedList *history;
public:
    BrowserHistory(string homepage) {
        history = new DoubleLinkedList(homepage);
    }
    
    void visit(string url) {
        if(history->next){
            DoubleLinkedList* temp = history;
            temp = temp->next;
            history->next = nullptr;
            while(temp){
                DoubleLinkedList* to_delete = temp;
                temp = temp->next;
                delete to_delete;
            }
        }
        DoubleLinkedList *new_node = new DoubleLinkedList(url);
        history->next = new_node;
        new_node->prev = history;
        history = history->next;
    }
    
    string back(int steps) {
        while(steps && history->prev){
            history = history->prev;
            steps --;
        }
        return history->val;
    }
    
    string forward(int steps) {
        while(steps && history->next){
            history = history->next;
            steps --;
        }
        return history->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
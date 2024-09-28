class Node {
public:
    int val;
    Node* next = NULL;
    Node* prv = NULL;
    Node(int v) {
        val = v;
        next = NULL;
        prv = NULL;
    }
};

class MyCircularDeque {
public:
    Node* head;
    Node* tail;
    int maxSize = 0;
    int size;

    MyCircularDeque(int k) {
        head = new Node(-1);
        tail = new Node(-1);
        maxSize = k;
        size = 0;
        head->next = tail;
        tail->prv = head;
    }

    bool insertFront(int value) {
        if (size == maxSize)
            return false;
        Node* h = new Node(value);
        Node* p = head->next;
        head->next = h;
        h->next = p;
        p->prv = h;
        h->prv = head;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (size == maxSize)
            return false;
        Node* t = new Node(value);
        Node* p = tail->prv;
        t->prv = p;
        p->next = t;
        tail->prv = t;
        t->next = tail;
        size++;
        return true;
    }

    bool deleteFront() {
        if (size != 0) {
            Node *h = head->next;
            Node *hh = h->next;
            hh->prv = head;
            head->next = hh;
            delete (h);
            size--;
            return true;
        }
        return false;
    }

    bool deleteLast() {
        if (size != 0) {
            Node *t = tail->prv;
            Node *tt = t->prv;
            tt->next = tail;
            tail->prv = tt;
            delete (t);
            size--;
            return true;
        }
        return false;
    }

    int getFront() {
        if (size == 0)
            return -1;
        return head->next->val;
    }

    int getRear() {
        if (size == 0)
            return -1;
        return tail->prv->val;
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == maxSize; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
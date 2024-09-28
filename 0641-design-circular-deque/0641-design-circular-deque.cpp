class Node {
public:
    int val;
    Node *next, *prev;
    Node(int val) {
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};
class MyCircularDeque {

    int size, maxSize;
    Node *head, *tail;

public:
    MyCircularDeque(int k) {
        size = 0, maxSize = k;
        head = nullptr;
        tail = nullptr;
    }

    bool insertFront(int value) {
        if (size == maxSize)
            return false;

        Node* newNode = new Node(value);

        if (size == 0) {
            head = tail = newNode;
            size++;
            return true;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        tail->next = head;
        head->prev = tail;
        size++;

        return true;
    }

    bool insertLast(int value) {
        if (size == maxSize)
            return false;

        Node* newNode = new Node(value);
        if (size == 0) {
            head = tail = newNode;
            size++;
            return true;
        }

        newNode->next = head;
        head->prev = newNode;
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++;

        return true;
    }

    bool deleteFront() {
        if (size == 0)
            return false;

        if (size == 1) {
            head = tail = nullptr;
            size = 0;
            return true;
        }
        head = head->next;
        tail->next = head;
        head->prev = tail;
        size--;
        return true;
    }

    bool deleteLast() {
        if (!size)
            return false;

        if (size == 1) {
            head = tail = nullptr;
            size = 0;
            return true;
        }

        Node* prevNode = tail->prev;
        prevNode->next = head;
        head->prev = prevNode;
        tail = prevNode;

        // Node* temp = head;
        // while (temp->next != tail)
        //     temp = temp->next;
        // temp->next = temp->next->next;
        // tail = temp;
        size--;
        return true;
    }

    int getFront() {
        if (!size)
            return -1;

        return head->val;
    }

    int getRear() {
        if (!size)
            return -1;

        return tail->val;
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
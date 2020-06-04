#include <iostream>

using namespace std;

class Node {
    private:
        Node* next;
        int value;
    
    public:
        Node(int value) {
            this->value = value;
        }

        void setNext(Node* target) {
            this->next = target;
        }

        int getValue() {
            return this->value;
        }
};

class Linked_List {
    private:
        Node* front;
        Node* tail;
        int size = 0;
    
    public:
        Linked_List() {}

        int getSize() {
            return size;
        }

        void insert_front(Node* newNode) {
            newNode->setNext(front);
            front = newNode;
            if(size == 0) tail = newNode;
            size++;
        }

        int getFront() {
            return front->getValue();
        }

        int getTail() {
            return tail->getValue();
        }
};

int main() {
    Linked_List* newLL = new Linked_List();
    newLL->insert_front(new Node(1));
    newLL->insert_front(new Node(2));
    newLL->insert_front(new Node(3));
    newLL->insert_front(new Node(4));
    newLL->insert_front(new Node(5));

    cout<<newLL->getFront()<<endl;
    cout<<newLL->getTail()<<endl;
}
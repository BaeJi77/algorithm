#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* pre;
    Node(int e){
        data = e;
        next = NULL;
        pre = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void tail_insert(int e){
        Node* insert = new Node(e);
        if(head == NULL){
            head = insert;
            tail = insert;
            insert->next = tail;
            insert->pre = head;
        }else{
            tail->next = insert;
            insert->pre = tail;
            tail = insert;
        }
    }
    
    void head_insert(int e){
        Node* insert = new Node(e);
        if(head == NULL){
            head = insert;
            tail = insert;
            insert->next = tail;
            insert->pre = head;
        }else{
            insert->next = head;
            head->pre = insert;
            head = insert;
        }
    }
    
    void head_remove(){
        Node* temp = head;
        head = head->next;
        
        delete temp;
    }
    
    void tail_remove(){
        Node* temp = tail;
        tail = tail->pre;
        
        delete temp;
    }
    
    int front(){
        return head->data;
    }
    
    int rear(){
        return tail->data;
    }
};

class queue{
public:
    int n;
    LinkedList* LL;
    
    queue(){
        n = 0;
        LL = new LinkedList();
    }
    
    int size(){
        return n;
    }
    
    bool empty(){
        return n==0;
    }
    
    void front_push(int e){
        n++;
        LL->head_insert(e);
    }
    
    void back_push(int e){
        n++;
        LL->tail_insert(e);
    }
    
    int front(){
        if(empty()) return -1;
        return LL->front();
    }
    
    int back(){
        if(empty()) return -1;
        return LL->rear();
    }
    
    int front_pop(){
        if(empty()) return -1;
        int ret = front();
        n--;
        LL->head_remove();
        return ret;
    }
    
    int back_pop(){
        if(empty()) return -1;
        int ret = back();
        n--;
        LL->tail_remove();
        return ret;
    }
    
    
};

int arr[104];

int main(){
    //    freopen("input.txt", "r", stdin);
    
}


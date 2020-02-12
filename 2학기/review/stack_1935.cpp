//  https://www.acmicpc.net/problem/1935
//  stack_1935.cpp
//  2학기
//
//  Created by Hoon on 2018. 10. 4..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


class Node{
public:
    int data;
    Node* next;
    Node(int e){
        data = e;
        next = NULL;
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
    
    void insert(int e){
        Node* insert = new Node(e);
        if(head == NULL){
            head = insert;
            tail = insert;
            insert->next = tail;
        }else{
            insert->next = head;
            head = insert;
        }
    }
    
    void remove(){
        Node* temp = head;
        head = head->next;
        
        delete temp;
    }
    
    int front(){
        return head->data;
    }
};

class stack{
public:
    int n;
    LinkedList* LL;
    
    stack(){
        n = 0;
        LL = new LinkedList();
    }
    
    int size(){
        return n;
    }
    
    bool empty(){
        return n==0;
    }
    
    void push(int e){
        n++;
        LL->insert(e);
    }
    
    int top(){
        if(empty()) return -1;
        return LL->front();
    }
    
    int pop(){
        if(empty()) return -1;
        int ret = top();
        n--;
        LL->remove();
        return ret;
    }
};

int N,arr[30];

int main(){
    stack st;
    scanf("%d" , &N);
    string str;
    cin>>str;
    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d" , &a);
        st.push(a);
    }
    
    for (int i = 0; i < N; i++) {
        int op = str[i];
        if(op == '+'){
            int a = st.pop();
            int b = st.pop();
            st.push(a+b);
        }else if(op == '-'){
            int b = st.pop();
            int a = st.pop();
            st.push(a-b);
        }else if(op == '*'){
            int a = st.pop();
            int b = st.pop();
            st.push(a*b);
        }else if(op == '/'){
            int b = st.pop();
            int a = st.pop();
            st.push(a/b);
        }
    }
}

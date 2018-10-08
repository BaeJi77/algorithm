#include <iostream>
#include <cstdio>
#include <cstring>

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
            tail->next = insert;
            tail = insert;
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
    
    void push(int e){
        n++;
        LL->insert(e);
    }
    
    int front(){
        if(empty()) return -1;
        return LL->front();
    }
    
    int pop(){
        if(empty()) return -1;
        int ret = front();
        n--;
        LL->remove();
        return ret;
    }
    
    int back(){
        if(empty()) return -1;
        return LL->rear();
    }
};

int arr[104];

int findMax(int N){
    int MAXX = 0;
    for(int i = 0 ; i < N ; i++){
        if(MAXX < arr[i])
            MAXX = arr[i];
    }
    
    return MAXX;
}


int main(){
//    freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    while(test--){
        int N,M;
        queue qu;
        queue indexQ;
        memset(arr,0,sizeof(arr));
        scanf("%d %d" , &N,&M);
        for(int i = 0 ; i < N ; i++){
            scanf("%d" , &arr[i]);
            qu.push(arr[i]);
            indexQ.push(i);
        }

        
        int cnt=1;
        while(!qu.empty()){
            int MAXX = findMax(N);
            
            while(MAXX != qu.front()){
                int temp = qu.pop();
                qu.push(temp);
                int qq = indexQ.pop();
                indexQ.push(qq);
            }
            
            int nowIndex = indexQ.front();

            if(nowIndex == M){
                break;
            }
            
            qu.pop();
            indexQ.pop();
            cnt++;
            
            arr[nowIndex] = -1;
        }
        cout<<cnt<<endl;
        while(!qu.empty()) qu.pop();
    }
}

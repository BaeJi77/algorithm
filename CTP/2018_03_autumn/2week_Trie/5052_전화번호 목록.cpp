//  https://www.acmicpc.net/problem/5052
//  5052_전화번호 목록.cpp
//  2학기
//
//  Created by Hoon on 2018. 10. 1..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NUMBER = 10;

class TrieNode{
private:
    TrieNode* children[NUMBER];
    bool ended;
public:
    TrieNode(){
        ended = false;
        for (int i = 0; i < NUMBER; i++) {
            children[i] = nullptr;
        }
    }
    
    ~TrieNode(){
        for (int i = 0; i < NUMBER; i++) {
            if(children[i])
                delete children[i];
        }
    }
    
    void insert(const char* key){
        if(*key == '\0'){
            ended = true;
            return;
        }else{
            int next = (*key) - '0';
            if(children[next] == nullptr){
                children[next] = new TrieNode();
            }
            
            children[next]->insert(key+1);
        }
    }
    
    bool isConsistent(const char* key){
        if(*key == '\0') return true;
        else if(ended == true) return false;
        else{
            int next = (*key) - '0';
            return children[next]->isConsistent(key +1);
        }
    }
};

int main(){
    int test;
    scanf("%d" , &test);
    while (test--) {
        int N;
        scanf("%d" , &N);
        TrieNode* root = new TrieNode();
        vector<string> vt;
        getchar();
        for (int i = 0; i < N; i++) {
            string inputStr;
            getline(cin,inputStr);
            vt.push_back(inputStr);
            
            root->insert(inputStr.c_str());
//            cout<<inputStr<<endl;
        }
        
        bool print = true;
        for (int i = 0; i < N; i++) {
            bool result = root->isConsistent(vt[i].c_str());
            if(result == false){
                print = false;
                break;
            }
        }
        
        if(print == true)
            printf("YES\n");
        else
            printf("NO\n");
        root->~TrieNode();
    }
}

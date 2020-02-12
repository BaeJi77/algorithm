//  https://www.acmicpc.net/problem/14425
//  14425_문자열 집합.cpp
//  2학기
//
//  Created by Hoon on 2018. 10. 1..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

const int ALPHABETS = 26;

class TrieNode{
private:
    TrieNode* children[ALPHABETS];
    bool ended;
public:
    TrieNode(){
        ended = false;
        for (int i = 0; i < ALPHABETS; i++) {
            children[i] = 0;
        }
    }
    
    ~TrieNode(){
        for (int i = 0; i < ALPHABETS; i++) {
            if(children[i])
                delete children[i];
        }
    }
    
    void insert(const char* key){
        if(*key == '\0'){
            ended = true;
            return;
        }else{
            int next = (*key) - 'a';
            if(children[next] == 0){
                children[next] = new TrieNode();
            }
            
            children[next]->insert(key + 1);
        }
    }
    
    bool sameCntCheck(const char* key){
        if(*key == '\0' && ended == true)
            return true;
        else if(*key == '\0' && ended == false)
            return false;
        else{
            int next = (*key) - 'a';
            if(children[next] == 0){
                return false;
            }
            
            return children[next]->sameCntCheck(key +1);
        }
    }
};

int main(){
    int N,M;
    scanf("%d %d" , &N,&M);
    TrieNode* root = new TrieNode();
    for (int i = 0; i < N; i++) {
        string inputStr;
        cin>>inputStr;
        root->insert(inputStr.c_str());
    }
    
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        string inputStr;
        cin>>inputStr;
        
        if(root->sameCntCheck(inputStr.c_str())){
            cnt++;
        }
    }
    
    printf("%d" , cnt);
}

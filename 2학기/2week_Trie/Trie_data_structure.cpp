//
//  Trie_data_structure.cpp
//  2학기
//
//  Created by Hoon on 2018. 10. 1..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

const int ALPHABETS =26;

class TrieNode{
private:
    TrieNode* children[ALPHABETS];
    bool terminal;
public:
    TrieNode(){
        terminal = false;
        for (int i = 0; i < ALPHABETS; i++) {
            children[i] = nullptr;
        }
    }
    ~TrieNode(){
        for (int i = 0; i < ALPHABETS; i++) {
            if(children[i])
                delete children[i];
        }
    };
    
    void insert(const char* key){
        if(*key == '\0'){
            terminal = true;
            return;
        }else{
            int next = (*key) - 'A';
            if(children[next] == nullptr){
                children[next] = new TrieNode();
            }
            
            children[next]->insert(key+1);
        }
    }
    
    bool isConsistent(const char* key){
        if(*key == '\0') return true;
        else if(terminal == true) return false;
        else{
            int next = (*key) - '0';
            return children[next]->isConsistent(key + 1);
        }
    }
};

int main(){
    
}

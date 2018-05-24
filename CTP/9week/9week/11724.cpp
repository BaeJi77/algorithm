//
//  11724.cpp
//  111
//
//  Created by Hoon on 2018. 5. 22..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int point , N;
int X1,X2;
vector <vector <int> > input;
bool visited[1004];
int cnt;

void dfs(int here){
    visited[here] = true;
    for(int i = 0 ; i < input[here].size() ; i++){
        int there = input[here][i];
        if(!visited[there])
        {
            dfs(there);
        }
    }
}

int main(){
    scanf("%d %d" , &point , &N);
    input.resize(point+1);
    while(N--){
        scanf("%d %d" , &X1 , &X2);
        input[X1].push_back(X2);
        input[X2].push_back(X1);
    }
    
    for(int i = 1 ; i <= point ; i++){
//        for(int j = 0 ; j < input[i].size() ; j++){
//            int here = input[i][j];
            if(!visited[i]){
                dfs(i);
                cnt++;
            }
//        }
    }
    printf("%d" , cnt);
}

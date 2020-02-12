//
//  5014.cpp
//  summer_week1
//
//  Created by Hoon on 2018. 7. 5..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

int F, S, G, U, D; //f 총 층수, g 목적지 ,s 현재 위치, u 상승버튼, d 다운버튼
int cnt;
queue<int> qu;
bool visited[1000010];
bool notOk;

bool isposs(int val){
    return (val>0) && (val<=1000000);
}

void bfs(int start){
    qu.push(start);
    visited[start] = true;
    while (int s = qu.size()) {
        while (s--) {
            int val = qu.front();
            if(val == G) return;
            qu.pop();
            if(isposs(val+U) && visited[val+U] == false){
                qu.push(val+U);
                visited[val+U] = true;
            }
            if(isposs(val-D) && visited[val-D] == false){
                qu.push(val-D);
                visited[val-D] = true;
            }

        }
        cnt++;
    }
    notOk = true;
}

int main(){
    scanf("%d %d %d %d %d",&F, &S, &G, &U, &D);
    bfs(S);
    //가지 못하는 경우
    if(notOk == true) printf("use the stairs");
    else printf("%d" , cnt);
}


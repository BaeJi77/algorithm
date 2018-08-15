//  https://www.acmicpc.net/problem/2843
//  2843_마블.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 15..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <stack>
using namespace std;

int N,Q;
//bool cycle;
int p[300004];
int line[300004];
bool cycle[300004],check[300004];
int q[300004][2]; // 0: 판단, 1: 해당 숫자;
int out[300004];
stack<int> ans;

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void Merge(int u , int v){
    if(u == 0 || v== 0) return;
    int uu = find(u);
    int vv = find(v);
    if(uu == vv) cycle[uu] = true;
    else p[uu] = vv;
}

void init(){
    for (int i = 1; i<=N; i++) {
        p[i] = i;
    }
}

int main(){
    scanf("%d" , &N);
    init();
    for (int i = 1 ; i <= N; i++) {
        scanf("%d" , &line[i]);
//        scanf("%d" , &p[i]);
//        if(p[i] == 0) p[i] = i;
//        line[i] = p[i];
    }
    
    scanf("%d" , &Q);
    for (int i = 1; i <= Q; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        q[i][0] = a;
        q[i][1] = b;
        if(a == 2) check[b] = true;
    }

    //이 부분 없으면 메모리 초과!!
    for (int i = 1; i <= N; i++) {
        if(check[i] == false) Merge(i , line[i]);
    }
    
    int outCnt = 0;
    for (int i = Q; i >= 1 ; i--) {
        if(q[i][0] == 1){
            outCnt++;
            bool nowCycle = cycle[find(q[i][1])];
            //싸이클이 있는지 없는지 체크;
            if(nowCycle == true) out[outCnt] = -1;
            else out[outCnt] = find(q[i][1]);
//            if(nowCycle == true) ans.push(-1);
//            else ans.push(find(q[i][1]));
        }else{
            //첫번째 인자가 부모
            Merge(q[i][1], line[q[i][1]]);
        }
    }
    
    for (int i = outCnt; i >= 1; i--) {
        if(out[i] == -1) printf("CIKLUS\n");
        else printf("%d\n" , out[i]);
    }
    
//    while (ans.size()) {
//        if(ans.top() == -1) printf("CIKLUS\n");
//        else printf("%d\n" , ans.top());
//        ans.pop();
//    }
}

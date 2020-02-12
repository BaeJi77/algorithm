//  https://www.acmicpc.net/problem/13306
//  13306_트리.cpp
//  summer_week7-Disjoint_Set
//
//  Created by Hoon on 2018. 8. 14..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <cstring>
#include <stack>
using namespace std;

int N,Q;
int p[200004];
int line[200004];
int query[500004][3]; //0 : 판단, 1 : 기본적으로 들어오는 수, 2 : 연결가능성 보기
stack<bool> ans;

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool Merge(int u, int v){
    int uu = find(u);
    int vv = find(v);
    if(uu==vv) return false;
    p[vv] = uu;
    return true;
}

void init(){
    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }
}

int main(){
    scanf("%d %d" , &N, &Q);
    init();
    for (int i = 2; i <= N; i++) {
        int a;
        scanf("%d" , &a);
        line[i] = a;
    }
    
    Q += N-1;
    for (int i = 0; i < Q; i++) {
        int a,b;
        scanf("%d %d" , &a,&b);
        query[i][0] = a;
        query[i][1] = b;
        if(a == 1) {
            int c;
            scanf("%d" , &c);
            query[i][2] = c;
        }
    }
    
    for (int i = Q - 1; i >= 0; i--) {
        if(query[i][0] == 0){
            Merge(query[i][1], line[query[i][1]]);
        }else{
            if(find(query[i][1]) == find(query[i][2])) ans.push(true);
            else ans.push(false);
        }
    }
    
    while (ans.size()) {
        if(ans.top() == true) printf("YES\n");
        else printf("NO\n");
        ans.pop();
    }
}

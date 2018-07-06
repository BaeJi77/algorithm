////
////  main.cpp
////  summer_week1
////
////  Created by Hoon on 2018. 7. 2..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#include <queue>
//
//using namespace std;
//
//bool visited[1010];
//queue <int> qu;
//vector <vector <int> > vt;
//int n,p,root;
//int v,u;
//
//void dfs(int here){
//    visited[here] = true;
//    printf("%d " , here);
//    for (int i = 0; i < vt[here].size(); i++) {
//        int there = vt[here][i];
//        if(visited[there] == false) dfs(there);
//    }
//}
//
//void bfs(int here){
//    visited[here] = true;
//    qu.push(here);
//    while (qu.size()) {
//        int next = qu.front();
//        qu.pop();
//        printf("%d " , next);
//        for (int i = 0 ; i < vt[next].size(); i++) {
//            int there = vt[next][i];
//            if(visited[there] == false){
//                qu.push(there);
//                visited[there] = true;
//            }
//        }
//    }
//}
//
//
//int main(int argc, const char * argv[]) {
//    scanf("%d %d %d" , &n, &p,&root);
//    vt.resize(n+1);
//    for(int i = 0 ; i < p ; i++) {
//        scanf("%d %d" , &v , &u);
//        vt[v].push_back(u);
//        vt[u].push_back(v);
//    }
//    
//    for(int i = 0 ; i < n ; i++){
//        sort(vt[i].begin() , vt[i].end());
//    }
//    
//    dfs(root);
//    printf("\n");
//    memset(visited, 0, sizeof(visited));
//    bfs(root);
//}


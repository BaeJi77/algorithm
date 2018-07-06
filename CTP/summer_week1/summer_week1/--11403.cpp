////
////  11403.cpp
////  summer_week1
////
////  Created by Hoon on 2018. 7. 4..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <cstring>
//#include <iostream>
//using namespace std;
//vector<vector<int> > map;
//bool visited[110];
//int n,input;
//int cnt;
//
//void dfs(int here){
//    visited[here] = true;
//    cnt++;
//    for (int i = 0; i < map[here].size(); i++) {
//        int there = map[here][i];
//        if(visited[there] == false) dfs(there);
//    }
//}
//
//int main(){
//    cin>>n;
//    map.resize(n+1);
//    for (int i = 0 ; i < n; i++) {
//        for (int j = 0 ; j < n; j++) {
//            scanf("%d" , &input);
//            if(input == 1){
//                map[i].push_back(j);
//           //     map[j].push_back(i);
//            }
//        }
//    }
//
//    for (int i = 0; i < n; i++) {
//        memset(visited, 0, sizeof(visited));
//        cnt = 0;
//        for (int j = 0 ; j < map[i].size(); j++) {
//            int here = map[i][j];
//            if(visited[here] == false) dfs(here);
//        }
////        printf("cnt %d\n" , cnt);
//        for (int j = 0; j < n; j++) {
//            if(visited[j] == true) printf("%d " , 1);
//            else printf("%d ", 0);
//        }
//        printf("\n");
//    }
//}
//

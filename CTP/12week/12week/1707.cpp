////
////  main.cpp
////  12week
////
////  Created by Hoon on 2018. 5. 25..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int k,v,e,p,q;
////int arr[20010][20010];
//vector<vector<int > > vt;
//bool visited[20010];
//bool check;
//void dfs(int here){
//    visited[here] = true;
//    for (int i = 0 ; i < vt[here].size(); i++) {
//        int there = vt[here][i];
//        if (visited[there] == true) {
//            check = true;
//        }else {
//            dfs(there);
//            
//        }
//    }
//}
//
//int main(int argc, const char * argv[]) {
//    scanf("%d" , &k);
//    while (k--) {
//        scanf("%d %d" , &v , &e);
//        vt.resize(v+1);
//        while (e--) {
//            scanf("%d %d" , &p,&q);
//            vt[p].push_back(q);
////            vt[q].push_back(p);
//        }
//        
//        for (int i = 0; i < vt.size(); i++) {
//            for (int j = 0 ; j < vt[i].size(); j++) {
//                int here = vt[i][j];
//                if(visited[here] == false) {
//                    dfs(here);
//                }
//            }
//        }
//        if (check == true) {
//            printf("NO\n");
//        }else{
//            printf("YES\n");
//        }
//        check = false;
//        vt.clear();
//    }
//}


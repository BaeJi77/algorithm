////
////  1697.cpp
////  summer_week1
////
////  Created by Hoon on 2018. 7. 4..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <queue>
//using namespace std;
//queue<int> qu;
//int a,b,cnt;
//bool visited[100010];
//
//void bfs(int here){
//    qu.push(here);
//    visited[here] = true;
//    while (int s = qu.size()) {
//        while (s--) {
//            int val = qu.front();
//            if(val == b) return;
//            qu.pop();
//            if(val*2 <= 100000 && visited[val*2] == false){
//                qu.push(val*2);
//                visited[val*2] = true;
//            }
//            if(val+1 <= 100000 && visited[val+1] == false){
//                qu.push(val+1);
//                visited[val+1] = true;
//            }
//            if(val-1 >= 0 && visited[val-1] == false) {
//                qu.push(val-1);
//                visited[val-1] = true;
//            }
//        }
//        cnt++;
//    }
//}
//
//int main(){
//    scanf("%d %d" , &a ,&b);
//    bfs(a);
//    printf("%d" , cnt);
//}


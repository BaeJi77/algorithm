////
////  5014.cpp
////  11week
////
////  Created by Hoon on 2018. 6. 7..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include <queue>
//
//using namespace std;
//int F,S,G,U,D;
//int visited[10001000];
//int cnt = 0;
//bool arrive = 0;
//
//bool itsok(int num){
//    if(num>0&&num<=F)
//    return true;
//    return false;
//
//}
//void bfs(int v){
//
//    queue<int> q;
//    q.push(v);
//    visited[v] = 1;
//    while(int s= q.size()){
//        while(s--){
//            int xv = q.front();
//            q.pop();
//            if(xv == G){
//                arrive = 1;
//                return;
//            }
//            int nv = xv + U;
//            if(!visited[nv]&&itsok(nv))
//            {q.push(nv);
//                visited[nv] = 1;
//            }
//            nv = xv - D;
//            if(!visited[nv]&&itsok(nv))
//            {q.push(nv);
//                visited[nv] = 1;
//            }
//
//        }
//        cnt++;
//    }
//}
//int main(){
//    cin>>F>>S>>G>>U>>D;
//    bfs(S);
//    if(arrive)
//    cout<<cnt;
//    else
//    cout<<"use the stairs";
//
//}


////
////  2589.cpp
////  111
////
////  Created by Hoon on 2018. 6. 4..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <iostream>
//#include <cstdio>
//#include <string>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//int ylen,xlen;
//string temp;
//int box[60][60];
//int visited[60][60];
//int nextx[4] = {0,0,-1,1};
//int nexty[4] = {1,-1,0,0};
//int ans = 0;
//int bfs(int y,int x){
//    int cnt = -1;
//    queue<pair<int,int>> q;
//    q.push(make_pair(y, x));
//    visited[y][x] = 1;
//    while(int s = q.size()){
//        while(s--){
//            int yv = q.front().first;
//            int xv = q.front().second;
//            q.pop();
//            int nx,ny;
//            for(int i=0;i<4;i++){
//                nx = xv + nextx[i];
//                ny = yv + nexty[i];
//                if(box[ny][nx] == 'L'&&!visited[ny][nx])
//                {visited[ny][nx] = 1;
//                    q.push(make_pair(ny, nx));
//
//                }
//
//            }
//
//        }
//        cnt++;
//    }
//    return cnt;
//
//}
//int main(){
//    cin>>ylen>>xlen;
//    for(int i=0;i<ylen;i++){
//        cin>>temp;
//        for(int j=0;j<xlen;j++){
//            box[i][j] = temp[j];
//        }
//    }
//
//    for(int i=0;i<ylen;i++){
//        for(int j=0;j<xlen;j++){
//            if(box[i][j]=='L'&&!visited[i][j])
//            {
//                ans = max(ans,bfs(i,j));
//                memset(visited,0,sizeof(visited));
//            }
//        }
//    }
//    cout<<ans;
//}
//

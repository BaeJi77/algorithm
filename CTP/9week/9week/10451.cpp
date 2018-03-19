<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> add185c... 18.07.06
////
////  10451.cpp
////  111
////
////  Created by Hoon on 2018. 5. 24..
////  Copyright © 2018년 Hoon. All rights reserved.
////
<<<<<<< HEAD
//
//#include <stdio.h>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//vector<vector<int> > vt;
//int t,n,m,cnt;
//bool visited[1010];
//
//void dfs(int here){
//    visited[here] = true;
//    for (int i = 0; i < vt[here].size(); i++) {
//        int there = vt[here][i];
//        if(visited[there] == false) dfs(there);
//    }
//}
//
//int main(){
//    scanf("%d" , &t);
//    while (t--) {
//        scanf("%d" , &n);
//        memset(visited, 0, sizeof(visited));
//        vt.resize(n+1);
//        for(int i = 1 ; i <= n ; i++){
//            scanf("%d" , &m);
//            vt[i].push_back(m);
//            vt[m].push_back(i);
//        }
//        
//        for (int i = 0 ; i < vt.size(); i++) {
//            for (int j = 0; j < vt[i].size(); j++) {
//                int here = vt[i][j];
//                if(visited[here] == false) {
//                    dfs(here);
//                }
//            }
//        }
//        printf("%d\n" , cnt);
//        cnt = 0;
//        vt.clear();
//    }
//}
//
//
=======
=======
>>>>>>> add185c... 18.07.06
//
//#include <stdio.h>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//vector<vector<int> > vt;
//int t,n,m,cnt;
//bool visited[1010];
//
//void dfs(int here){
//    visited[here] = true;
//    for (int i = 0; i < vt[here].size(); i++) {
//        int there = vt[here][i];
//        if(visited[there] == false) dfs(there);
//    }
//}
//
//int main(){
//    scanf("%d" , &t);
//    while (t--) {
//        scanf("%d" , &n);
//        memset(visited, 0, sizeof(visited));
//        vt.resize(n+1);
//        for(int i = 1 ; i <= n ; i++){
//            scanf("%d" , &m);
//            vt[i].push_back(m);
//            vt[m].push_back(i);
//        }
//        
//        for (int i = 0 ; i < vt.size(); i++) {
//            for (int j = 0; j < vt[i].size(); j++) {
//                int here = vt[i][j];
//                if(visited[here] == false) {
//                    dfs(here);
//                }
//            }
//        }
//        printf("%d\n" , cnt);
//        cnt = 0;
//        vt.clear();
//    }
//}
//
//
<<<<<<< HEAD

#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int> > vt;
int t,n,m,cnt;
bool visited[1010];

void dfs(int here){
    visited[here] = true;
    for (int i = 0; i < vt[here].size(); i++) {
        int there = vt[here][i];
        if(visited[there] == false) dfs(there);
    }
}

int main(){
    scanf("%d" , &t);
    while (t--) {
        scanf("%d" , &n);
        memset(visited, 0, sizeof(visited));
        vt.resize(n+1);
        for(int i = 1 ; i <= n ; i++){
            scanf("%d" , &m);
            vt[i].push_back(m);
            vt[m].push_back(i);
        }
        
        for (int i = 0 ; i < vt.size(); i++) {
            for (int j = 0; j < vt[i].size(); j++) {
                int here = vt[i][j];
                if(visited[here] == false) {
                    dfs(here);
                    cnt++;
                }
            }
        }
        printf("%d\n" , cnt);
        cnt = 0;
        vt.clear();
    }
}

>>>>>>> 69999cd... 18.05.29
=======
>>>>>>> add185c... 18.07.06

////  https://www.acmicpc.net/problem/7795
////  7795_먹을 것인가 먹힐 것인가.cpp
////  summer_week3-2
////
////  Created by Hoon on 2018. 7. 19..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//int T,n,m;
//int p[20004];
//int q[20004];
//
//int main(){
//    scanf("%d" , &T);
//    while (T--) {
//        memset(p,0,sizeof(p));
//        memset(q,0,sizeof(q));
//        scanf("%d %d" , &n,&m);
//        for (int i = 0 ; i < n; i++) {
//            scanf("%d" , &p[i]);
//        }
//        for (int i = 0 ; i < m; i++) {
//            scanf("%d" , &q[i]);
//        }
//        sort(p, p+n);
//        sort(q, q+m);
//
//        int ans = 0;
//        for(int i = 0 ; i < n ; i++){
//            ans += lower_bound(q, q+m, p[i]) - q;
//        }
//        printf("%d\n" , ans);
//    }
//}


////  https://www.acmicpc.net/problem/4796
////  4796_캠핑.cpp
////  summer_week4-1
////
////  Created by Hoon on 2018. 7. 23..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <cstdio>
//
//
//using namespace std;
//
//int L, P, V , outNumber , ans;
//
//int main(){
//    while (1) {
//        scanf("%d %d %d" , &L, &P, &V);
//        if(L == 0 && P == 0 && V == 0) break;
//        outNumber++;
//        ans = 0;
//        int tempV = V;
//        int value = tempV/P;
//        tempV = tempV % P;
//        ans += L*value;
//        if(tempV > L){
//            ans += L;
//        }else{
//            ans += tempV;
//        }
//        if(ans > V) ans = V;
//        printf("Case %d: %d\n" , outNumber , ans);
//    }
//}


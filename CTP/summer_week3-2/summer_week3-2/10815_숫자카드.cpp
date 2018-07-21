////  https://www.acmicpc.net/problem/10815
////  10815_숫자카드.cpp
////  summer_week3-2
////
////  Created by Hoon on 2018. 7. 19..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <cstdio>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int n,m,left,right;
//
//int p[500004];
//
//int find(int number){
//    //index로 접근함. 그래서 left는 0, right는 n임
//    left = 0;
//    right = n;
//    while (left <= right) {
//        int mid = (left+right)/2;
//        if(number < p[mid]) right = mid -1;
//        else if(number > p[mid]) left = mid +1;
//        else return 1; //number == p[mid]
//    }
//    return 0;
//}
//
//int main() {
//    scanf("%d" , &n);
//    for (int i = 0 ; i < n; i++) {
//        scanf("%d" , &p[i]);
//    }
//    sort(p,p+n);
//    scanf("%d" , &m);
//    for (int i = 0 ; i < m; i++) {
//        int input = 0;
//        scanf("%d" , &input);
//        int ans = find(input);
//        printf("%d " , ans);
//    }
//}
//

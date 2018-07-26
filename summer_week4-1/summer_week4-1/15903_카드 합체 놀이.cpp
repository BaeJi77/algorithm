////
////  15903_카드 합체 놀이.cpp
////  summer_week4-1
////
////  Created by Hoon on 2018. 7. 24..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <queue>
//
//using namespace std;
//typedef long long ll;
//
//ll n,m,sum;
//priority_queue<ll> pq;
//
//int main(){
//    scanf("%lld %lld" , &n,&m);
//    for (int i = 0; i < n; i++) {
//        ll input = 0;
//        scanf("%lld" , &input);
//        pq.push(-input);
//    }
//
//    for (int i = 0; i < m; i++) {
//        ll first = -pq.top();
//        pq.pop();
//        ll second = -pq.top();
//        pq.pop();
//        ll insert = first + second;
//        pq.push(-insert);
//        pq.push(-insert);
//    }
//
//    for (int i = 0; i < n; i++) {
//        sum += -pq.top();
//        pq.pop();
//    }
//
//    printf("%lld" , sum);
//}
//
//

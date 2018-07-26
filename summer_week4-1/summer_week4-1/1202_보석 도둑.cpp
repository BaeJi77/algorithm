////  https://www.acmicpc.net/problem/1202
////  1202_보석 도둑.cpp
////  summer_week4-1
////
////  Created by Hoon on 2018. 7. 24..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <queue>
//using namespace std;
//typedef long long ll;
//ll n,k,sum;
//priority_queue<pair<int, int>> pq;
//vector<pair<ll, ll>> vt;
//multiset<ll> bag;
//vector<ll> ans;
//int main(){
//    scanf("%lld %lld" , &n,&k);
//    for (ll i = 0; i < n; i++) {
//        ll a,b;
//        scanf("%lld %lld" , &a,&b);
//        pq.push({b,a});
//    }
//
//    for (ll i = 0 ; i < k; i++) {
//        ll a;
//        scanf("%lld" , &a);
//        bag.insert(a);
//    }
//    while (pq.size()) {
//        ll value = pq.top().first;
//        ll weight = pq.top().second;
//        pq.pop();
//        auto it = bag.lower_bound(weight);
//        if(it == bag.end()){
//            continue;
//        }
//        bag.erase(it);
//        sum+= value;
//    }
//    printf("%lld" , sum);
//}
//

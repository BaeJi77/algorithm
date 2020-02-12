////  https://www.acmicpc.net/problem/1208
////  1208_부분집합의 합 2.cpp
////  summer_week3-2
////
////  Created by Hoon on 2018. 7. 19..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//
//ll n,k,mid,input;
//ll cnt;
//bool odd;
//vector<ll> vt1;
//vector<ll> vt2;
//vector<ll> x;
//vector<ll> y;
//
//void init(){
//    scanf("%lld %lld" , &n , &k);
//    mid = n/2;
//    if(n%2 == 1) odd = true;
//    for (int i = 0 ; i < mid; i++) {
//        
//        scanf("%lld" , &input);
//        vt1.push_back(input);
//    }
//    if(odd){
//        for (int i = 0 ; i < mid+1; i++) {
//            
//            scanf("%lld" , &input);
//            vt2.push_back(input);
//        }
//    }else {
//        for (int i = 0; i < mid; i++) {
//            
//            scanf("%lld" , &input);
//            vt2.push_back(input);
//        }
//    }
//}
//
//int main(){
//    init();
//    
//    for (int i = 0; i < (1<<mid); ++i) {
//        int sum = 0;
//        for (int j = 0; j < mid; ++j) {
//            if(i&(1<<j)){
//                sum += vt1[j];
//            }
//        }
//        x.push_back(sum);
//    }
//    if(odd){
//        for (int i = 0; i < (1<<(n-mid)); ++i) {
//            int sum = 0;
//            for (int j = 0; j < (n-mid); ++j) {
//                if(i&(1<<j)){
//                    sum += vt2[j];
//                }
//            }
//            y.push_back(sum);
//        }
//    }else{
//        for (int i = 0; i < (1<<mid); ++i) {
//            int sum = 0;
//            for (int j = 0; j < mid; ++j) {
//                if(i&(1<<j)){
//                    sum += vt2[j];
//                }
//            }
//            y.push_back(sum);
//        }
//    }
//    
//    sort(x.begin(), x.end());
//    sort(y.begin(), y.end());
//    
//    for (int i = 0; i < x.size(); i++) {
//        // x[i] + y[???] = k; => y[???] = k - x[i];
//        cnt += upper_bound(y.begin(), y.end(), k-x[i]) - lower_bound(y.begin(), y.end(), k-x[i]);
//    }
//    
//    if(k == 0) printf("%lld" , --cnt);
//    else printf("%lld" , cnt);
//    
//}


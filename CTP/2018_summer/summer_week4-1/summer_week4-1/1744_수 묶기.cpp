////
////  1744_수 묶기.cpp
////  summer_week4-1
////
////  Created by Hoon on 2018. 7. 23..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> plus;
//vector<int> minus;
//
//int n,input,ans;
//bool plusOdd, minusOdd , zero;
//
//int main(){
//    scanf("%d" , &n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d" , &input);
//        if(input == 1) ans++;
//        else if(input == 0) zero = true;
//        else if(input > 0) plus.push_back(input);
//        else minus.push_back(input);
//    }
//    sort(plus.begin() , plus.end());
//    reverse(plus.begin(), plus.end());
//    sort(minus.begin(), minus.end());
//
//    if(plus.size()%2 == 1) {
//        plusOdd = true;
//    }
//    if(minus.size()%2 == 1)
//        minusOdd = true;
//
//    if(plusOdd){
//        if(plus.size() != 1){
//            for (int i = 0; i < plus.size()/2; i++) {
//                ans += plus[2*i] * plus[2*i+1];
//            }
//        }
//        ans += plus.back();
//    }else{
//        for (int i = 0; i < plus.size()/2; i++) {
//            ans += plus[2*i] * plus[2*i+1];
//        }
//    }
//
//    if(minusOdd){
//        if(minus.size() != 1){ //size가 1이 아닌 경우만
//            for (int i = 0; i < minus.size()/2; i++) {
//                ans += minus[2*i] * minus[2*i+1];
//            }
//        }
//        if(zero == false) ans += minus.back();
//    }else{
//        for (int i = 0; i < minus.size()/2; i++) {
//            ans += minus[2*i] * minus[2*i+1];
//        }
//    }
//
//    printf("%d" , ans);
//}
//

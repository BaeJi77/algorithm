////
////  1931_회의실 배정.cpp
////  summer_week4-1
////
////  Created by Hoon on 2018. 7. 23..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <algorithm>
//#include <limits.h>
//#include <vector>
//using namespace std;
//
//int n,endTime,startTime,cnt;
//vector<pair<int, int> > vt;
//
//int main(){
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        int first,second = 0;
//        scanf("%d %d" , &second , &first);
//        vt.push_back({first,second});
//    }
//    //first : 끝나는 시간 second : 시작하는 시간
//    sort(vt.begin(), vt.end());
//
//
//    endTime = INT_MIN;
//    //끝시간은 현재 이 배열에서 끝
//    for (int i = 0; i < n; i++) {
//        if(vt[i].second >= endTime){
//            endTime = vt[i].first;
//            cnt++;
//        }
//    }
//
//    printf("%d" , cnt);
//}
//

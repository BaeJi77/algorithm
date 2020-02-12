////  https://www.acmicpc.net/problem/13913
////  13913_숨바꼭질 4.cpp
////  summer_week5-1
////
////  Created by Hoon on 2018. 8. 1..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <stdio.h>
//#include <queue>
//#include <cstring>
//#include <stack>
//using namespace std;
//
//int sp,ep;
//int dist[100004];
//int back[100004];
//stack<int> st;
//priority_queue<pair<int ,pair<int, int>>> pq;
//
//
//bool isposs(int x){
//    return x>=0 && x<=100000;
//}
//
//int dij(int startPoint){
//    pq.push({0,{startPoint,-1}});
//    while (!pq.empty()) {
//        int count = -pq.top().first;
//        int point = pq.top().second.first;
//        int previous = pq.top().second.second;
//        pq.pop();
//
//        if(dist[point] != -1) continue;
//        back[point] = previous;
//        dist[point] = count;
//
//        if(point == ep) return count;
//
//        count++;
//        if(isposs(point*2) && dist[point*2] == -1) pq.push({-count,{point*2,point}});
//        if(isposs(point-1) && dist[point-1] == -1) pq.push({-count,{point-1,point}});
//        if(isposs(point+1) && dist[point+1] == -1) pq.push({-count,{point+1,point}});
//    }
//    return -1;
//}
//
//int main(){
//    scanf("%d %d" , &sp,&ep);
//    memset(dist,-1,sizeof(dist));
//    int ans = dij(sp);
//
//    printf("%d\n" , ans);
//    int backNumber = ep;
//    while (backNumber != -1) {
//        st.push(backNumber);
//        backNumber = back[backNumber];
//    }
//
//    while (!st.empty()) {
//        printf("%d " , st.top());
//        st.pop();
//    }
//}


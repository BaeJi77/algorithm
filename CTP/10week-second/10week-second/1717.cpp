////
////  1717.cpp
////  10week-second
////
////  Created by Hoon on 2018. 5. 11..
////  Copyright © 2018년 Hoon. All rights reserved.
////
//
//#include <cstdio>
//#include <vector>
//
//using namespace std;
//
//int n,m;
//int x,y,z;
//
//vector <int> parent;
//
//int find(int number){
//    if(parent[number] < 0) return number;
//    int root = find(parent[number]);
//    parent[number] = root;
//    return parent[number];
//}
//
//bool set(int xx, int yy){
//    int XX = find(xx);
//    int YY = find(yy);
//    if(XX == YY) return false;
//    parent[XX] = YY;
//    return true;
//}
//
//
//int main(int argc, const char * argv[]) {
//    scanf("%d %d" , &n , &m);
//    for(int i = 0 ; i <= n ; i++){
//        parent.push_back(-1);
//    }
//    for(int i = 0 ; i < m ; i++){
//        scanf("%d %d %d" , &x , &y ,&z);
//        if(x == 0){
//            set(y, z);
//        }else {
//            int YY = find(y);
//            int ZZ = find(z);
//            if(YY == ZZ) printf("YES\n");
//            else printf("NO\n");
//        }
//    }
//    return 0;
//}


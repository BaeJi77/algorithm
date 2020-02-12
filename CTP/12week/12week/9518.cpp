<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> add185c... 18.07.06
////
////  9518.cpp
////  12week
////
////  Created by Hoon on 2018. 5. 25..
////  Copyright © 2018년 Hoon. All rights reserved.
////
<<<<<<< HEAD
//
//#include <stdio.h>
//#include <string>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int X,Y;
//string str;
//int arr[60][60];
//int cnt,maxx,qq;
//int aaa;
//
//int xx[8] = {1,1,1,-1,-1,-1,0,0};
//int yy[8] = {1,0,-1,1,0,-1,1,-1};
//
//void dfs(int y, int x){
//    for(int i = 0 ; i < 8 ; i++){
//        int dx = x+xx[i];
//        int dy = y+yy[i];
//        
//        if(dx<0 || dy <0 || dx >= X || dy >= Y) continue;
//        if(arr[dy][dx] == 0) cnt++;;
//        
//    }
//}
//
//int main(){
//    scanf("%d %d" , &Y,&X);
//    getchar();
//    for(int i = 0 ; i < Y ; i++){
//        getline(cin, str);
//        for (int j = 0 ; j < X; j++) {
//            if (str[j] == '.') {
//                arr[i][j] = 1;
//            }else{
//                arr[i][j] = 0;
//            }
//        }
//    }
//    
//    for (int i = 0 ; i < Y; i++) {
//        for (int j =0; j < X; j++) {
//            if(arr[i][j] == 0) aaa++;
//        }
//    }
//
//    if(aaa==0) {
//        printf("0");
//        return 0;
//    }
//    
//    for (int i = 0; i < Y; i++) {
//        for(int j = 0 ; j < X ; j++){
//            if(arr[i][j] == 1) {
//                dfs(i, j);
//                qq++;
//            };
//            maxx = max(maxx,cnt);
//            cnt = 0;
//        }
//    }
//    printf("%d",maxx);
//}

=======
=======
>>>>>>> add185c... 18.07.06
//
//#include <stdio.h>
//#include <string>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int X,Y;
//string str;
//int arr[60][60];
//int cnt,maxx,qq;
//int aaa;
//
//int xx[8] = {1,1,1,-1,-1,-1,0,0};
//int yy[8] = {1,0,-1,1,0,-1,1,-1};
//
//void dfs(int y, int x){
//    for(int i = 0 ; i < 8 ; i++){
//        int dx = x+xx[i];
//        int dy = y+yy[i];
//        
//        if(dx<0 || dy <0 || dx >= X || dy >= Y) continue;
//        if(arr[dy][dx] == 0) cnt++;;
//        
//    }
//}
//
//int main(){
//    scanf("%d %d" , &Y,&X);
//    getchar();
//    for(int i = 0 ; i < Y ; i++){
//        getline(cin, str);
//        for (int j = 0 ; j < X; j++) {
//            if (str[j] == '.') {
//                arr[i][j] = 1;
//            }else{
//                arr[i][j] = 0;
//            }
//        }
//    }
//    
//    for (int i = 0 ; i < Y; i++) {
//        for (int j =0; j < X; j++) {
//            if(arr[i][j] == 0) aaa++;
//        }
//    }
//
//    if(aaa==0) {
//        printf("0");
//        return 0;
//    }
//    
//    for (int i = 0; i < Y; i++) {
//        for(int j = 0 ; j < X ; j++){
//            if(arr[i][j] == 1) {
//                dfs(i, j);
//                qq++;
//            };
//            maxx = max(maxx,cnt);
//            cnt = 0;
//        }
//    }
//    printf("%d",maxx);
//}

<<<<<<< HEAD
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int X,Y;
string str;
int arr[60][60];
int cnt,maxx,qq;
int aaa;

int xx[8] = {1,1,1,-1,-1,-1,0,0};
int yy[8] = {1,0,-1,1,0,-1,1,-1};

void dfs(int y, int x){
    for(int i = 0 ; i < 8 ; i++){
        int dx = x+xx[i];
        int dy = y+yy[i];
        
        if(dx<0 || dy <0 || dx >= X || dy >= Y) continue;
        if(arr[dy][dx] == 0) cnt++;;
        
    }
}

int main(){
    scanf("%d %d" , &Y,&X);
    getchar();
    for(int i = 0 ; i < Y ; i++){
        getline(cin, str);
        for (int j = 0 ; j < X; j++) {
            if (str[j] == '.') {
                arr[i][j] = 1;
            }else{
                arr[i][j] = 0;
            }
        }
    }
    
    for (int i = 0 ; i < Y; i++) {
        for (int j =0; j < X; j++) {
            if(arr[i][j] == 0) aaa++;
        }
    }

    if(aaa==0) {
        printf("0");
        return 0;
    }
    
    for (int i = 0; i < Y; i++) {
        for(int j = 0 ; j < X ; j++){
            if(arr[i][j] == 1) {
                dfs(i, j);
                qq++;
            };
            maxx = max(maxx,cnt);
            cnt = 0;
        }
    }
    printf("%d",maxx);
}
>>>>>>> 69999cd... 18.05.29
=======
>>>>>>> add185c... 18.07.06

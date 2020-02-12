//  https://www.acmicpc.net/problem/1992
//  1992_쿼드트리.cpp
//  basic
//
//  Created by Hoon on 2018. 8. 9..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int n;
int qt[70][70];

void solve(int y,int x,int size){
    if(size==1) cout<<qt[y][x];
    else{
        bool check = true;
        int base = qt[y][x];
        for (int i = y; i < y+size; i++) {
            for (int j = x; j < x+size; j++) {
                if(base != qt[i][j]) {
                    check = false;
                    break;
                }
            }
            if(check == false) break;
        }
        
        if(check == true) {
            cout<<qt[y][x];
        }else{
            //Y,X는 시작점이기때문에 그것은 2로 나누거나 하는 것이 아니고
            //더하거나 빼줘서 이동시켜야한다!!!
            cout<<"(";
            solve(y ,   x,size/2);
            solve(y ,   x + size/2, size/2);
            solve(y + size/2, x, size/2);
            solve(y + size/2, x + size/2, size/2);
            cout<<")";
        }
    }
}

int main(){
    scanf("%d" , &n);
    for (int i = 0; i < n; i++) {
        string input = "";
        cin>>input;
        for (int j = 0 ; j < n; j++) {
            qt[i][j] = input[j] - '0';
        }
    }
    solve(0,0,n);
}

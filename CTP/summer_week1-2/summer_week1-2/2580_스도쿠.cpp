//  https://www.acmicpc.net/problem/2580
//  2580_스도쿠.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 8. 22..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>

using namespace std;

int map[10][10];

bool findEmptySpace(int &row,int &col){
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if(map[i][j] == 0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool safeRow(int num , int row , int col){
    for (int i = 1; i<= 9; i++) {
        if(map[row][i] == num) return false;
    }
    return true;
}

bool safeCol(int num, int row, int col){
    for (int i = 1; i <= 9; i++) {
        if(map[i][col] == num) return false;
    }
    return true;
}

bool safeBox(int num, int row,int col){
    int boxRow,boxCol;
    if(row % 3 == 0) boxRow = row/3-1;
    else boxRow = (row/3);
    
    if(col % 3 == 0) boxCol = col/3-1;
    else boxCol = (col/3);
    for (int i = boxRow*3+1; i <= (boxRow+1)*3 ; i++) {
        for (int j = boxCol*3+1; j <= (boxCol+1)*3 ; j++) {
            if(map[i][j] == num) return false;
        }
    }
    return true;
}

bool isSafe(int num, int row, int col){
    if(safeRow(num,row,col) && safeCol(num,row,col) && safeBox(num,row,col))
        return true;
    return false;
}

bool solve(){
    int row,col;
    
    if(findEmptySpace(row,col) == false)
        return true;
    
    for (int num = 1; num <= 9; num++) {
        if(isSafe(num,row,col)){
            map[row][col] = num;
            if(solve() == true)
                return true;
            
            map[row][col] = 0;
        }
    }
    
    return false;
}

void printMap(){
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <=9; j++) {
            printf("%d " , map[i][j]);
        }
        puts("");
    }
}

int main(){
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            scanf("%d" , &map[i][j]);
        }
    }
    
    solve();
    printMap();
}

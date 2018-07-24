//  https://www.acmicpc.net/problem/2632
//  2632_피자판매.cpp
//  summer_week3-2
//
//  Created by Hoon on 2018. 7. 23..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

int goal,m,n,cnt;
int apizza[1004];
int bpizza[1004];
vector<int> vt1;
vector<int> vt2;


void partitialSum(int arr[] , int size , int k){
    int tempSum = 0;
    //    tempSum = arr[0];
    for (int i = 0 ; i < size; i++) {
        if(arr[i] > goal) {
            tempSum = 0;
            continue;
        }
        if(tempSum + arr[i] > goal){
            
        }
    }
}

int main(){
    scanf("%d" , &goal);
    scanf("%d %d" , &m,&n);
    for (int i = 0 ; i < m; i++) {
        scanf("%d" , &apizza[i]);
    }
    
    for (int i = 0 ; i < n; i++) {
        scanf("%d" , &bpizza[i]);
    }
    
    partitialSum(apizza,m,1);
    partitialSum(bpizza,n,2);
    for (int i = 0; i < vt1.size(); i++) {
        printf("%d " , vt1[i]);
    }
    puts("");
    
    for (int i = 0; i < vt1.size(); i++) {
        cnt += upper_bound(vt2.begin(), vt2.end(), goal-vt1[i]) - lower_bound(vt2.begin(), vt2.end(), goal=vt1[i]);
    }
    
    printf("%d" , cnt);
}

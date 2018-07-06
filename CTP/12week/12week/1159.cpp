//
//  1159.cpp
//  12week
//
//  Created by Hoon on 2018. 6. 10..
//  Copyright © 2018년 Hoon. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int n;
int arr[30];
bool check;

int main(){
    scanf("%d" , &n);
    while (n--) {
        string str="";
        cin>>str;
        int temp = str[0] - 'a';
        arr[temp]++;
    }
    for(int i = 0 ; i < 30; i++){
        if(arr[i] >= 5){
            printf("%c" , i+'a');
            check =true;
        }
    }

    if(check == false) cout<<"PREDAJA";
}

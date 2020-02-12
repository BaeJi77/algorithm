//
//  2966.cpp
//  11week_second
//
//  Created by Hoon on 2018. 5. 18..
//  Copyright © 2018년 Hoon. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

char A[110];
char B[110];
char G[110];
int acnt;
int bcnt;
int gcnt;
int maxx;


int n;
string str;

void set(){
    for(int i = 0 ; i < 100 ; i++){
        if(i%3==0){
            A[i] = 'A';
        }else if(i%3 == 1){
            A[i] = 'B';
        }else{
            A[i] = 'C';
        }
    }
    for(int i = 0 ; i < 100 ; i++){
        if(i%4 == 0 || i%4 == 2){
            B[i] = 'B';
        }else if(i%4 == 1){
            B[i] = 'A';
        }else{
            B[i] = 'C';
        }
    }
    for(int i = 0 ; i < 100 ; i++){
        if(i%6 == 0 || i%6 == 1){
            G[i] = 'C';
        }else if(i%6 == 2||i%6 == 3){
            G[i] = 'A';
        }else{
            G[i] = 'B';
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    set();
    scanf("%d" , &n);
    getchar();
    getline(cin, str);
    for(int i = 0 ; i < n ; i++){
        if(A[i] == str[i]) acnt++;
        if(B[i] == str[i]) bcnt++;
        if(G[i] == str[i]) gcnt++;
        int tempMAX = max(acnt,bcnt);
        maxx = max(tempMAX, gcnt);
    }

    printf("%d\n" , maxx);
    if(acnt==maxx) printf("Adrian\n");
    if(bcnt==maxx) printf("Bruno\n");
    if(gcnt==maxx) printf("Goran\n");
    return 0;
}


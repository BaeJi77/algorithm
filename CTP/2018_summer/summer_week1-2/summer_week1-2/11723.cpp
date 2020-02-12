//
//  main.cpp
//  summer_week1-2
//
//  Created by Hoon on 2018. 7. 5..
//  Copyright © 2018년 Hoon. All rights reserved.
//
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int t,in;
char ch[1010];
int a;


int main(int argc, const char * argv[]) {
    scanf(" %d", &t);
    while (t--) {
        scanf("%s" , ch);
        if(ch[0] == "all"){
            a = (1<<31) -1;
        }else if(ch == "empty"){
            a = 0;
        }else {
            scanf("%d" , &in);
            if(ch == "check"){
                int temp = a&(1<<in);
                if(temp == 0 ) printf("0\n");
                else printf("1\n");
            }else if(ch == "remove"){
                a = a&~(1<<in);
            }else if(ch[0] == 't'){
                a = a^(1<<in);
            }else if(ch[0] == 'a'){
                a = a|(1<<in);
            }
        }

    }
    return 0;
}


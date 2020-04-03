#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

int N;
long long M;
string str;


// 왼 => 공 (공)*size |
// 오 => | (공)*size 공 
// 양쪽 => | (공)*size |
void printRightLine() {
    printf(" ");
    for(int i = 0 ; i < N ; i++) {
        printf(" ");
    }
    printf("|");
}

void printLeftLine() {
    printf("|");
    for(int i = 0 ; i < N ; i++) {
        printf(" ");
    }
    printf(" ");
}

void printBothLine() {
    printf("|");
    for(int i = 0 ; i < N ; i++) {
        printf(" ");
    }
    printf("|");
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %lld", &N, &M);
    str = to_string(M);

    for(int i = 0 ; i < str.size() ; i++) {
        printf(" ");
        for(int j = 0 ; j < N ; j++) {
            if(str[i] == '1' || str[i] == '4')
                printf(" ");
            else printf("-");
        }
        printf("  ");
    }
    puts("");

    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < str.size() ; j++) {
            if(str[j] == '5' || str[j] == '6') printLeftLine();
            else if(str[j] == '1' || str[j] == '2' || str[j] == '3' || str[j] == '7') printRightLine();
            else printBothLine();
            printf(" ");
        }
        printf(" \n");
    }

    for(int i = 0 ; i < str.size() ; i++) {
        printf(" ");
        for(int j = 0 ; j < N ; j++) {
            if(str[i] == '1' || str[i] == '7' || str[i] == '0')
                printf(" ");
            else printf("-");
        }
        printf("  ");
    }
    puts("");

    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < str.size() ; j++) {
            if(str[j] == '2') printLeftLine();
            else if(str[j] == '3' || str[j] == '4' || str[j] == '9' || str[j] == '7' || str[j] == '1' || str[j] == '5') printRightLine();
            else printBothLine();
            printf(" ");
        }
        printf(" \n");
    }

    for(int i = 0 ; i < str.size() ; i++) {
        printf(" ");
        for(int j = 0 ; j < N ; j++) {
            if(str[i] == '1' || str[i] == '7' || str[i] == '4')
                printf(" ");
            else printf("-");
        }
        printf("  ");
    }
    puts("");
}
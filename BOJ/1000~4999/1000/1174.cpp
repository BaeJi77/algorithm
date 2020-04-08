#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N, ans;

int solve(int digit, int pre, int number) {
    if(digit == 1) {
        return 1;
    }

    int cnt = 0;
    for(int i = pre - 1; i >= 0 ; i--) {
        cnt += solve(digit - 1, i, number * 10 + i);
    }

    return cnt;
}


int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    if(N < 10) {
        printf("%d", N - 1);
        return 0;
    }

    int ans = 9;
    int digit = 2;
    while(1) {

        for(int i = 9 ; i >= digit - 1; i--) {
                
        }
    }
}
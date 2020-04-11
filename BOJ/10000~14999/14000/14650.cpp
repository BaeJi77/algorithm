#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;
const int numbers[] = {0, 1, 2};

int N, cnt;


int solve(int digit, int number) {
    if(digit == 1) {
        if(number % 3 == 0) return 1;
        return 0;
    }

    int ret = 0;
    for(int i = 0 ; i < 3 ; i++) {
        ret += solve(digit - 1, number * 10 + numbers[i]);
    }

    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    printf("%d", solve(N, 1) + solve(N, 2));
}
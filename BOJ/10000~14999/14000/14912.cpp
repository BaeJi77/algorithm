#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, D, ans;

int calDigitCount(int num) {
    int ret = 0;
    while(num != 0) {
        if(num % 10 == D) ret++;
        num /= 10;
    }
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &D);
    for(int i = 1 ; i <= N ; ++i) {
        ans += calDigitCount(i);
    }
    printf("%d", ans);
}
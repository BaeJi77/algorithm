#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int pre[1000010];

int countZero(int number) {
    int cnt = 0;
    while(number != 0) {
        if(number % 10 == 0) cnt++;
        number /= 10;
    }
    return cnt;
}

void init() {
    pre[0] = 1;
    int number = 1;
    while(1) {
        if(number == 1000001)
            break;
        
        pre[number] = countZero(number);
        number++;
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    init();

    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int cnt = 0;
        for(int i = a ; i <= b ; i++) {
            cnt += pre[i];
        }
        printf("%d\n", cnt);
    }
}
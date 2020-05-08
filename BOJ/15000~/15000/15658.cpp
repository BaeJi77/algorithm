#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

const int MAX = 1e9;

int N;
int maxAns = -MAX - 10;
int minAns = MAX + 10;
int numbers[20];
int oper[10];

void solve(int value, int idx, int add, int subtract, int product, int division) { // idx => 숫자, 
    if(idx == N) {
        maxAns = max(maxAns, value);
        minAns = min(minAns, value);
        return ;
    }

    if(add != 0) solve(value + numbers[idx], idx + 1, add - 1, subtract, product, division);
    if(subtract != 0) solve(value - numbers[idx], idx + 1, add, subtract - 1, product, division);
    if(product != 0) solve(value * numbers[idx], idx + 1, add, subtract, product - 1, division);
    if(division != 0) solve(value / numbers[idx], idx + 1, add, subtract, product, division - 1);
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &numbers[i]);
    }

    for(int i = 0 ; i < 4 ; i++) {
        scanf("%d", &oper[i]);
    }

    solve(numbers[0], 1, oper[0], oper[1], oper[2], oper[3]);
    printf("%d\n%d", maxAns, minAns);
}
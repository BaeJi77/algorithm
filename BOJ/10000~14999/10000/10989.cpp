#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

int N;
int numbers[10010];

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; ++i) {
        int a;
        scanf("%d", &a);
        numbers[a]++;
    }

    for(int i = 1 ; i <= 10000 ; ++i) {
        for(int j = 0 ; j < numbers[i] ; ++j)
            printf("%d\n", i);
    }
}
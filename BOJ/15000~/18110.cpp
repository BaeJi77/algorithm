#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;
const int SIZE = 3e5;

int N;
int num[SIZE+10];

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    if(N == 0) {
        printf("0");
        return 0;
    }
    
    for(int i = 0 ; i < N ; i++) {
        scanf("%d", &num[i]);
    }
    sort(num, num+N);
    double kk = (((double)N / 100) * 15) + 0.5;
    int outCnt = (int)kk;
    
    int sum = 0;
    int length = N - 2 * outCnt;
    for(int i = outCnt ; i < length + outCnt ; i++) {
        sum += num[i];
    }

    double avg = (double)sum / length + 0.5;
    printf("%d\n", (int)avg);
}
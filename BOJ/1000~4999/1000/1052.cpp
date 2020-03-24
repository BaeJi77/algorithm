#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
int N, K;

int countNumberOne(int num) {
    int cnt = 0;
    while(1) {
        if(num == 0) break;
        if(num % 2) cnt++;
        num /= 2;
    }
    return cnt;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    int newAns = 0;
    int addNumber = 0;
    while(1) {
        if(countNumberOne(N + addNumber) <= K)
            break;
        addNumber++;
    }
    printf("%d\n", addNumber);
}
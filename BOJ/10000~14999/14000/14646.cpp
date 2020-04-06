#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int N, ans, stickerCnt;
int num[100010];

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < 2 * N ; i++) {
        int q;
        scanf("%d", &q);
        num[q]++;
        if(num[q] == 1) {
            stickerCnt++;
        } else { // 2
            stickerCnt--;
        }

        ans = max(ans, stickerCnt);
    }
    printf("%d", ans);
}
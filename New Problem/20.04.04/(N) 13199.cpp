#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int P, M, F, C; // P: 치킨 사격, M: 치킨에 쓸 돈, F: 치킨시키는데 필요한 쿠폰 수, C: 시킨 시키면 주는 장수

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        int ans = 0;
        scanf("%d %d %d %d", &P, &M, &F, &C);
        int sang = (M / P);
        int sangCoupon = sang * C;
        // printf("\n%d\n", sang);
        int kk = 0;
        while(1) {
            int addChi = sangCoupon / F;
            kk = max(kk, addChi);
            printf("%d %d %d %d\n", sangCoupon, addChi, kk, kk * C);
            if(addChi == 0) break;
            sang += addChi;
            sangCoupon %= F;
            sangCoupon += addChi * C;
        }

        int doo = (M / P);
        doo += (doo * C) / F;
        // printf("%d %d\n", sang, doo);
        // 상언이가 두영이보다 더 많이 먹을 수 있는 치킨의 수
        printf("%d\n", sang - doo);
    }
}
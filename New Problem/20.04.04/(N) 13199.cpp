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
        int sang = 0;
        int sangCoupon = ((M / P * C) / F) * C;
        int temp = sangCoupon;
        // printf("Coupone:%d F: %d C: %d\n", sangCoupon , F, C);
        // while(1) {
        //     int addChi = sangCoupon / F;
        //     if(addChi == 0) break;
        //     // printf("%d %d %d %d %d\n", sangCoupon, addChi ,addChi * C, sangCoupon % F, sangCoupon % F + addChi * C);
        //     sang += addChi;
        //     sangCoupon %= F;
        //     sangCoupon += addChi * C;
        // }

        // 쿠폰을 쓰지도 못하는데 쿠폰을 땡겨씀.
        // 땡겨쓴 쿠폰은 안되지~~~
        // 쿠폰은 분명히 남아야 됨.
        // temp / (F - C)
        // 사면 안되는데 산 경우가 있겠지.
        // 여기서 값을 빼줘야 됨.
        // 남아있는 쿠폰이 C만큼은 있어야 한다?
        // F 

        // F + C
        // (F - C)
        // printf("%d\n", C / (F - C));
        int kk = (temp) / (F - C) - (F / (F - C));
        // if(F - C == 1) kk -= C;
        // if(temp % (F - C) == 0) kk -= C;
        // 상언이가 두영이보다 더 많이 먹을 수 있는 치킨의 수
        // printf("%d %d\n\n", sang, kk);
        printf("%d\n", kk);
    }
}
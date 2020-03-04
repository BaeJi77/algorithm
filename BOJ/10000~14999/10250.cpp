#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        int H,W,N;
        scanf("%d %d %d", &H, &W, &N);
        int floor = N % H == 0 ? H : N % H;
        int roomCnt = (N % H) == 0 ? N / H : N / H + 1;
        printf("%d%02d\n", floor, roomCnt);
    }
}
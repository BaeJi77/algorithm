#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;
typedef long long ll;

ll N, K;
ll npos, ny, nx;
ll midLine;

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%lld %lld", &N, &K);
    getchar();
    midLine = N + 1;

    ll ans = 1;
    npos = 1, ny = 1, nx = 1;
    for(ll i = 0 ; i < K ; i++) {
        char q = getchar();
        ll newy = ny, newx = nx;
        ll nextPos;
        if(q == 'D') {
            newy++;
            if(newy + nx <= N + 1) { // 왼쪽 위
                if((ny + nx) % 2 == 0) { // 짝수
                    nextPos = npos + (2 * ny);
                } else { // 홀수
                    nextPos = npos + (2 * nx - 1);
                } 
            } else { // 오른쪽 아래
                if((ny + nx) % 2 == 0) { // 짝수
                    nextPos = npos + 2 *(N - nx) + 1;
                } else { // 홀수
                    nextPos = npos + 2 * (N - ny);
                }
            }
        } else if(q == 'U') {
            newy--;
            if(ny + nx > N + 1) {
                if((ny + nx) % 2 == 0) { // 짝수
                    nextPos = npos - 2 * (N - (ny - 1));
                } else { // 홀수
                    nextPos = npos - (2 * N - 2 *(nx) + 1);
                }
            } else {
                if((ny + nx) % 2 == 0) { // 짝수
                    nextPos = npos - (2 * nx - 1);
                } else { // 홀수
                    nextPos = npos - (2 * (ny - 1));
                }
            }
        } else if(q == 'L') {
            newx--;
            if(nx + ny > N + 1) {
                if((ny + nx) % 2 == 0) {
                    nextPos = npos - 2 * (N - (ny)) - 1;
                } else {
                    nextPos = npos - 2 * (N - (nx-1));
                }
            } else {
                if((ny + nx) % 2 == 0) {
                    nextPos = npos - (2 * (nx - 1));
                } else { // 홀수
                    nextPos = npos - (2 * ny - 1);
                }
            }
        } else if(q == 'R') {
            newx++;
            if(newx + ny > N+1) {
                if((ny + nx) % 2 == 0) { // 짝수
                    nextPos = npos + 2 * (N - nx);
                } else { // 홀수
                    nextPos = npos + 2 * (N - ny) + 1;
                }
            } else { // 왼쪽 위
                if((ny + nx) % 2 == 0) { // 짝수
                    nextPos = npos + 2 * ny - 1;
                } else { // 홀수
                    nextPos = npos + 2 * nx;
                }
            }
            
        }
        npos = nextPos;
        ans += npos;
        ny = newy;
        nx = newx;
    }
    printf("%lld", ans);
}
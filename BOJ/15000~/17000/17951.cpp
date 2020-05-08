#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N, K;
int paper[100010];

int solve() {
    int ans = 0;
    int left = 0;
    int right = 20000000;
    while(left <= right) {
        int mid = (left + right) / 2; // 합의 최솟값의 점수
        int groupCnt = 0;
        int sum = 0;
        for(int i = 0 ; i < N ; i++) {
            sum += paper[i];
            if(sum >= mid) { // 최솟값을 넘긴 애들만 그룹 카운터를 해줌.
                groupCnt++;
                sum = 0;
            }
        }

        if(groupCnt < K) {
            right = mid - 1;
        } else { // 여기가 정해
            ans = max(ans, mid);
            left = mid + 1;
        }
    }
    return right;
}


int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &K);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &paper[i]);
    printf("%d", solve());
}
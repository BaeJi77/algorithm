#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N;
int left[2010];
int right[2010];
int dp[2010][2010];

int solve(int leftIdx, int rightIdx) {
    if(leftIdx == N || rightIdx == N) {
        return 0;
    }

    int& ret = dp[leftIdx][rightIdx];
    if(ret != -1)
        return ret;
    
    // 오른쪽이 더 적은 경우 오른쪽만 버림 => 이때 점수 획득
    // 같거나 왼쪽이 큰 경우는 왼쪽만 버리기 or 둘 다 버리기
    ret = 0;
    if(left[leftIdx] > right[rightIdx]) ret = max(ret, solve(leftIdx, rightIdx + 1) + right[rightIdx]);
    else {
        ret = max(ret, solve(leftIdx + 1, rightIdx));
        ret = max(ret, solve(leftIdx + 1, rightIdx + 1));
    }

    return ret;
}


int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &left[i]);

    for(int i = 0 ; i < N ; i++)
        scanf("%d", &right[i]);
    
    printf("%d", solve(0, 0));
}
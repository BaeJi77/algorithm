#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1e9;

int N,C;
int map[200001];

int checkDist(int mid) {
    int cnt = 1;
    int nowNetIndex = 0;

    // 옆을 봤는데 거리가 너무 멀어지면 공유기 하나 더 설치
    for(int i = 0  ; i < N ; i++) {
        // mid랑 값 비교해서 이 친구 값들이 mid보다 크면 새로운 라우터 설치해야됨
        if(map[i] - map[nowNetIndex] >= mid) {  
            cnt++;
            nowNetIndex = i;
        }
    }
    // 공유기가 만약 적게 설치된다고 하면 false 반환 => right 값 바꾸고
    // 공유기가 같거나 많이 설치 된다고 하면 true => left값 바꾸고ㅓ
    int ret;
    if(cnt < C)
        ret = 0;
    else 
        ret = 1;
    
    return ret;
}

int sol() {
    int left = 1;
    int right = MAX+1; 
    int ans = -1;
    while(left <= right) {
        int mid = (left + right) / 2; // 가장 인접한 두 공유기 사이의 거리
        int F = checkDist(mid);
        if(F) { // 많이 설치되거나 같은 경우
            ans = max(ans, mid);
            left = mid + 1;
        } else { // 적게 설치 된 경우
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &C);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &map[i]);
    sort(map, map + N);
    printf("%d", sol());
}
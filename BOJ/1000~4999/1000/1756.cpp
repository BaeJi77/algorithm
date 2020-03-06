#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1e9; // 10억

int D,N;
int arr[300010];
bool visited[300010];

int findGoodIdx(int newPizza, int nowPizzaIdx) {
    int ret = -1;
    int left = 0;
    int right = nowPizzaIdx;
    while(left <= right) {
        int mid = (left + right) / 2; //나에게 가장 딱 맞는 인덱스
        if(mid >= nowPizzaIdx && visited[nowPizzaIdx]) {
            right = mid - 1;
            continue;
        }

        if(newPizza > arr[mid]) { // 못들어감
            right = mid - 1;
        } else { // 들어갈 수 있음. 여기에 답이 있음.
            left = mid + 1;
            ret = max(ret, mid);
        }
    }
    return ret;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &D, &N);
    int nowWidth = MAX;
    for(int i = 0 ; i < D ; i++) {
        int k;
        scanf("%d", &k);
        if(nowWidth > k) { // 이전 놈들이 폭이 좁았으면 그 전 폭을 넘지 못하기에 저 작은 놈으로만 생각해야 함.
            nowWidth = k;
        }
        arr[i] = nowWidth;
    }

    int isNotPoss = false;
    int nowPizzaIdx = D - 1;
    for(int i = 0 ; i < N ; i++) {
        int k;
        scanf("%d", &k);
        
        int findIdx = findGoodIdx(k, nowPizzaIdx);
        visited[findIdx] = true;
        if(findIdx >= 0) {
            nowPizzaIdx = findIdx;
        } else {
            isNotPoss = true;
        }
    }

    if(isNotPoss) printf("0");
    else printf("%d", nowPizzaIdx + 1);
}
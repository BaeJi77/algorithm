#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

const int MAX = 300 * 100;
using namespace std;

int N,M;
int map[304];
vector<int> vt;

int func(int mid) {
    int arrayCnt = 0;
    int ssum = 0;
    bool biggerThanMidValue = false;
    // 최댓값이 넘기 전까지 담음
    for(int i = 0 ; i < N ; i++) {
        if(map[i] > mid) 
            biggerThanMidValue = true;
        
        ssum += map[i];
        if(ssum > mid) {
            arrayCnt++;
            ssum = map[i];
        }
    }
    if(ssum != 0)
        arrayCnt++;

    bool ans = false;
    if(arrayCnt > M) // 너무 많이 쪼개짐 => mid값이 작다는 것임 => mid값을 키워야 함.
        ans = true;

    // true: mid값을 키운다. false: mid값을 줄인다.
    // 그냥 밸류가 엄청 큰 놈이 있으면 무조건 mid를 키워야지.
    return biggerThanMidValue? 1 : ans;
}

int binary () {
    // int cnt = 0;
    int left = 0;
    int right = MAX+1;
    int ans = MAX;
    
    // 최댓값 중 최솟값 찾기
    while(left <= right) {
        int mid = (left + right) / 2;
        // true: 더 많이 쪼개는 경우 => 덜 쪼개야 됨 => mid값을 올려야지 / false: 덜 쪼갬, 더 쪼개야 됨 => mid 값을 내려야 함.
        int F = func(mid); 
        // printf("%d %d %d %d\n", left, right, mid, F);
        if(F) {
            left = mid + 1;
        } else { 
            right = mid - 1;
            ans = min(ans, mid);
        }
    }

    return ans;
}


int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++)
        scanf("%d", &map[i]);
    
    int ans = binary();
    printf("%d\n", ans);

    int ssum = 0;
    int layerCnt = 0;
    int addLayerCnt = 0;
    int sameLayerIndex = 0;
    int indexFlag = false;
    for (int i = 0 ; i < N ; i++) {
        layerCnt++;
        ssum += map[i];
        if(ssum == ans) {
            indexFlag = true;
            sameLayerIndex = vt.size();
            vt.push_back(layerCnt);
            ssum = 0;
            layerCnt = 0;
        } else if(ssum > ans) {
            ssum = map[i];
            vt.push_back(layerCnt - 1);
            layerCnt = 1;
        }
    }
    
    if(ssum) {
        if(indexFlag == false)
            sameLayerIndex = vt.size();
        vt.push_back(layerCnt);
    }
    addLayerCnt = M - vt.size();

    for(int i = 0 ; i < vt.size(); i++) {
        if(vt[i] == 1)  printf("%d ", vt[i]);
        if(vt[i] > 1 && addLayerCnt >= 1) {
            printf("1 ");
            addLayerCnt--; 
            vt[i]--;
            i--;
        }else
            printf("%d ", vt[i]);
    }
}
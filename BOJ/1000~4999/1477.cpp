#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, L;
vector<int> map;

int f (int mid) {
    int ret = 1;
    int nowDist = 0;
    int newRestLocationCnt = 0;
    for(int i = 1 ; i < map.size(); i++) {
        // newRestLocationCnt += (map[i] - map[i-1] - 1 ) / mid;
        while(1) {
            // 만약 거리가 mid만큼 안떨어져있으면 안세워도 됨.
            if(map[i] - nowDist <= mid) {
                nowDist = map[i];
                break;
            } else { // map[i] - nowDist > mid
                newRestLocationCnt++;
                nowDist += mid;
            }
        }
    }
    if(newRestLocationCnt > M) { // >인 경우 M보다 더 만들어야 함 => mid 값이 작았다.
        ret = 0;
    } 

    return ret;
}


int sol() {
    // 맨 마지막 (도로의 끝)도 휴게소가 없는 구간이라고 해야 됨
    int left = 0;
    int right = L;
    while(left <= right) {
        int mid = (left + right) / 2; // 휴게소가 없는 최대 구간
        int F = f(mid); 
        // printf("%d %d %d %d\n", left, right, mid, F);
        if(F) { // 가능 => 최소가 되기 위해 줄여야 함.
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left; // 안되는 것에 마지막.
}


int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d %d", &N, &M, &L);
    map.push_back(0);
    for(int i = 0 ; i < N ; i++) {
        int k;
        scanf("%d", &k);
        map.push_back(k);
    }
    map.push_back(L);

    sort(map.begin(), map.end());
    printf("%d", sol());
}

/*
3 1 1000
200 701 800
=> 251

6 7 800
622 411 201 555 755 82
=> 70
*/
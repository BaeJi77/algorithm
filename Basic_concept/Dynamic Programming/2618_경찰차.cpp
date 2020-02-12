#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX = 1000;

int N,W,cache[MAX+4][MAX+4];
vector<pair<int, int> > vt;
int fy,fx,sy,sx;
// int order[MAX+4];
vector<int> order;

int calDist(int ay, int ax, int by, int bx){
    return abs(ay - by) + abs(ax - bx);
}

//마지막으로 위치했던 인덱스 위치
int func(int aidx, int bidx){
    if(aidx == W || bidx == W){
        return 0;
    }

    int& ret = cache[aidx][bidx];
    if(ret != -1)
        return ret;

    int nextIdx = max(aidx, bidx) + 1;
    int adist, bdist;
    int aret, bret;
    
    int tfy = fy;
    int tfx = fx;
    adist = calDist(fy, fx, vt[nextIdx].second, vt[nextIdx].first);
    fy = vt[nextIdx].second;
    fx = vt[nextIdx].first;
    aret = func(nextIdx, bidx) + adist;
    fy = tfy;
    fx = tfx;

    int tsy = sy;
    int tsx = sx;
    bdist = calDist(sy, sx, vt[nextIdx].second, vt[nextIdx].first);
    sy = vt[nextIdx].second;
    sx = vt[nextIdx].first;
    bret = func(aidx, nextIdx) + bdist;
    sy = tsy;
    sx = tsx;

    ret = min(aret, bret);

    return ret;
}

void tracking(int aidx, int bidx){
    if(aidx == W || bidx == W)
        return;

    int nextIdx = max(aidx, bidx) + 1;
    int adist, bdist;
    int aret, bret;
    
    int tfy = fy;
    int tfx = fx;
    adist = calDist(fy, fx, vt[nextIdx].second, vt[nextIdx].first);
    fy = vt[nextIdx].second;
    fx = vt[nextIdx].first;
    aret = cache[nextIdx][bidx] + adist;
    fy = tfy;
    fx = tfx;

    int tsy = sy;
    int tsx = sx;
    bdist = calDist(sy, sx, vt[nextIdx].second, vt[nextIdx].first);
    sy = vt[nextIdx].second;
    sx = vt[nextIdx].first;
    bret = cache[aidx][nextIdx] + bdist;
    sy = tsy;
    sx = tsx;

    if(aret > bret){
        order.push_back(2);
        tracking(aidx, nextIdx);
    }else{
        order.push_back(1);
        tracking(nextIdx, bidx);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    scanf("%d", &W);
    vt.resize(N+1);
    for(int i = 1 ; i <= W; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        vt[i] = make_pair(a,b); // a: x, b : y
    }
    fy = 1;
    fx = 1;
    sy = N;
    sx = N;
    memset(cache,-1,sizeof(cache));
    printf("%d\n", func(0, 0));

    tracking(0,0);
    for(auto i : order){
        printf("%d\n", i);
    }
}
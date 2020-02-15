#include <cstdio>
#include <algorithm>

using namespace std;

int N,M;
int map[51][51];

bool isposs(int y, int x) {
    return y>=0&&x>=0&&y<N&&x<M;
}

int checkIsOkay(int y, int x, int sl) {
    int nowNumber = map[y][x];
    if(!isposs(y + sl, x) || nowNumber != map[y+sl][x])
        return 0;
    if(!isposs(y, x + sl) || nowNumber != map[y][x+sl])
        return 0;
    if(!isposs(y + sl, x + sl) || nowNumber != map[y+sl][x+sl])
        return 0;

    return 1;
}

int checkAllPoint(int squareLength) {
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            if(checkIsOkay(i, j, squareLength))
                return 1;
        }
    }
    return -1;
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0 ; i < N ; i++) {
        getchar();
        for(int j = 0 ; j < M; j++) {
            map[i][j] = getchar() - '0';
        }
    }

    int maxLength = min(N, M);
    int ret = -1;
    for(int i = 0 ; i <= maxLength ; i++) {
        //i는 쭉 보는 정사각형의 크기   
        if(checkAllPoint(i) == 1)
            ret = i;
    }
    
    ret++;
    printf("%d", ret*ret);
}
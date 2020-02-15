#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int map[101][101];

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        getchar();
        for(int j = 0 ; j < N ; j++) {
            char in = getchar();
            if(in == '.')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    }

    // 가로 체크
    int aret = 0;
    for(int i = 0 ; i < N ; i++) {
        int contiCnt = 0;
        for(int j = 0 ; j < N ; j++) {
            if(map[i][j] == 1) {
                contiCnt++;
            } 

            if(map[i][j] == 0)
                contiCnt = 0;

            if(contiCnt == 2) {
                aret++;
            }
        }
    }

    // 세로 체크
    int bret = 0;
    for(int i = 0 ; i < N ; i++) {
        int contiCnt = 0;
        for(int j = 0 ; j < N ; j++) {
            if(map[j][i] == 1) {
                contiCnt++;
            } 

            if(map[j][i] == 0)
                contiCnt = 0;

            if(contiCnt == 2) {
                bret++;
            }
        }
    }

    printf("%d %d\n", aret, bret);
}
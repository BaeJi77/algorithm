#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, K;
char map[1010][1010];
int jungle[1010][1010], sea[1010][1010], ice[1010][1010];
int jungle2[1010][1010], sea2[1010][1010], ice2[1010][1010];

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &N, &M);
    scanf("%d", &K);
    for(int i = 1 ; i <= N ; i++) {
        getchar();
        int jungleSum = 0;
        int seaSum = 0;
        int iceSum = 0;
        for(int j = 1 ; j <= M ; j++){
            char in = getchar();
            map[i][j] = in;
            if(in == 'J') jungleSum++;
            if(in == 'O') seaSum++;
            if(in == 'I') iceSum++;
            jungle[i][j] = jungleSum;
            sea[i][j] = seaSum;
            ice[i][j] = iceSum;
        }
    }

    for(int i = 1 ; i <= M ; i++) {
        int jungleSum = 0;
        int seaSum = 0;
        int iceSum = 0;
        for(int j = 1 ; j <= N ; j++) {
            jungleSum += jungle[j][i];
            seaSum += sea[j][i];
            iceSum += ice[j][i];
            jungle2[j][i] = jungleSum;
            sea2[j][i] = seaSum;
            ice2[j][i] = iceSum;
        }
    }

    for(int i = 0 ; i < K ; i++) {
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int jj = jungle2[c][d] - jungle2[a - 1][d] - jungle2[c][b - 1] + jungle2[a - 1][b - 1];
        int ss = sea2[c][d] - sea2[a - 1][d] - sea2[c][b - 1] + sea2[a - 1][b - 1];
        int ii = ice2[c][d] - ice2[a - 1][d] - ice2[c][b - 1] + ice2[a - 1][b - 1];
        printf("%d %d %d\n", jj, ss, ii);
    }
}
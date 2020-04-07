#include <cstdio>
#include <algorithm>

using namespace std;

int R, C;
int map[20][20];
int newMap[20][20];

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

bool isPoss(int y, int x) {
    return y >= 0 && y < R && x >= 0 && x < C;
}

bool isNotIslandAfter50Years(int y, int x) {
    int nearIslandCnt = 0;
    for(int i = 0 ; i < 4 ; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(isPoss(yy, xx) && map[yy][xx]) nearIslandCnt++;
    }

    if(nearIslandCnt <= 1) return 0;
    else return 1;
}

int main() {
    freopen("/Users/baejihoon/Desktop/algorithm/input.txt","r",stdin);
    scanf("%d %d", &R, &C);
    for(int i = 0 ; i < R ; i++) {
        getchar();
        for(int j = 0 ; j < C ; j++) {
            char in = getchar();
            if(in == '.') map[i][j] = 0;
            if(in == 'X') map[i][j] = 1;
        }
    }
    for(int i = 0 ; i  < R ; i++) {
        for(int j = 0 ; j < C ; j++) {
            if(map[i][j])
                newMap[i][j] = isNotIslandAfter50Years(i, j);
        }
    }
    int high = R-1;
    int low = 0;
    int left = C-1;
    int right = 0;
    for(int i = 0 ; i < R ; i++) {
        for(int j = 0 ; j < C ; j++) {
            if(newMap[i][j] == 1){
                left = min(left, j);
                right = max(right, j);
            }
        }
    }

    for(int i = 0 ; i < C ; i++) {
        for(int j = 0 ; j < R ; j++) {
            if(newMap[j][i] == 1){
                high = min(high, j);
                low = max(low, j);
            }
        }
    }

    for(int i = high ; i <= low ; i++) {
        for(int j = left ; j <= right ; j++) {
            printf("%c",newMap[i][j] == 1 ? 'X' : '.');
        }
        puts("");
    }
}
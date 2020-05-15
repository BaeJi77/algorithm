#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

#include <vector>
#include <queue>
#include <string>

using namespace std;

const int dy[] = {0, 1};
const int dx[] = {1, 0};

int N;
int maxx = -10000000;
int minn = 10000000;
char map[10][10];

bool isPoss(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int cal(int pre, int now, char oper) { 
    int result = 0;
    switch (oper)
    {
    case '+':
        result = pre + now;
        break;

    case '-':
        result = pre - now;
        break;

    case '*':
        result = pre * now;
        break;
    
    default:
        break;
    }
    return result;
}

void solve(int ny, int nx, int pre, char oper) {
    if(ny == N - 1 && nx == N - 1) {
        // 마지막 연산하고
        int result = cal(pre, map[ny][nx] - '0', oper);
        maxx = max(maxx, result);
        minn = min(minn, result);
        return;
    }

    // ny + nx가 홀수면 연산자
    if((ny + nx) % 2) {
        for(int i = 0 ; i < 2 ; ++i) {
            int y = ny + dy[i];
            int x = nx + dx[i];

            if(!isPoss(y, x)) continue;

            solve(y, x, pre, map[ny][nx]);
        }
    } else { // ny + nx가 짝수면 숫자 => 계산하고 넘겨야됨.
        int now;
        if(ny + nx == 0) now = map[ny][nx] - '0';
        else now = cal(pre, map[ny][nx] - '0', oper);

        for(int i = 0 ; i < 2 ; ++i) {
            int y = ny + dy[i];
            int x = nx + dx[i];

            if(!isPoss(y, x)) continue;

            solve(y, x, now, map[ny][nx]);
        }
    }
}

int main() {
    freopen("/Users/baejihoon/Desktop/PS/algorithm/input.txt","r",stdin);
    cin>>N;
    for(int i = 0 ; i < N ; ++i) {
        for(int j = 0 ; j < N ; ++j) {
            cin>>map[i][j];
        }
    }
    solve(0, 0, 0, '0');
    cout<<maxx<<" "<<minn;
}
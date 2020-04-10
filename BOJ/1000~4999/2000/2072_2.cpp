#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int N,y,x;
int pann[21][21];
pair<int, int> direction[4] = { { 0, 7 }, { 1, 6 }, { 2, 5 }, { 3, 4 } };
bool visited[21][21];
int ans = -1;

int isPoss(int y, int x) {
	return  y >= 1 && y <= 19 && x >= 1 && x <= 19;
}

int sol(int y, int x,int dir,int color) {
	visited[y][x] = true;
	int ret = 1;
	int dir1 = direction[dir].first;
	int dir2 = direction[dir].second;

	int nextY = y + dy[dir1], nextX = x + dx[dir1];
	if (!visited[nextY][nextX] && pann[nextY][nextX] == color)
		ret+=sol(nextY, nextX, dir, color);

	nextY = y + dy[dir2], nextX = x + dx[dir2];
	if (!visited[nextY][nextX] && pann[nextY][nextX] == color)
		ret += sol(nextY, nextX, dir, color);

	return ret;
}


int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &y, &x);
		int color = (i % 2) + 1;
		pann[y][x] = color;
		for (int j = 0; j < 4; j++) {
			memset(visited, 0, sizeof(visited));
			if (ans == -1 && sol(y, x, j, color) == 5) {
                ans = i;
                break;
            }
		}
        if(ans != -1) break;
	}
	printf("%d", ans);
}
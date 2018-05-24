#include <cstdio>
#include <cstring>
#include <vector>


using namespace std;

int T;
vector <vector <int> > input;
bool visited[54][54];
int bae[54][54];
int col , row , N;
int colPoint , rowPoint; 
int xx[4] = { 0 , 0 , 1 , -1};
int yy[4] = { 1 , -1 , 0 , 0};
int cnt;

void dfs(int x , int y){
	visited[x][y] = true;

	for(int i = 0 ; i < 4 ; i++){
		int tx = x + yy[i];
		int ty = y + xx[i];

		
		if(tx < 0 || ty < 0 || tx >= col || ty >= row) continue;
		if(visited[tx][ty] == true) continue;
		if(bae[tx][ty] == false) continue;
		dfs(tx,ty);
	}
}


int main(){
	freopen("input.txt" , "r" , stdin);
	scanf("%d" , &T);
	while(T--){
		memset(visited , 0 , sizeof(visited));
		memset(bae , 0 , sizeof(bae));
		scanf("%d %d %d" , &col , &row , &N);

		while(N--){
			scanf("%d %d" , &colPoint , &rowPoint);
			bae[colPoint][rowPoint] = 1;

		}
		for(int i = 0 ; i < col ; i++){
			for(int j = 0 ; j < row ; j++){
				if(!visited[i][j] && bae[i][j] == 1){
					dfs(i,j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
}

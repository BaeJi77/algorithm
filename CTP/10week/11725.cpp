#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector <vector <int> > vt;
bool visited[100010];
int parent[100010];
int N;
int x,y;
int findNumber;
// int parent;

void dfs(int here , int past){
	visited[here] = true;
	parent[here] = past;
	for(int i = 0 ; i < vt[here].size() ; i++){
		int there = vt[here][i];
		if(visited[there] == false) dfs(there , here);
	}
}



int main(){
	freopen("input.txt" , "r" , stdin);
	// memset(tree,-1,sizeof(tree));
	scanf("%d" , &N);
	vt.resize(N+1);
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d" , &x , &y);
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	memset(visited,0,sizeof(visited));
	dfs(1,1);
	for(int i = 2 ; i <= N ; i++){
		int past = parent[i];
		printf("%d\n", past);
	}

}

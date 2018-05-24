#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

vector <vector <int> > vt;
bool visited[60];
int N;
int x;
int y;
int cnt;
int root;
bool isErased[60];

void erase(int here){
	isErased[here]=true;
	for(int i = 0 ; i < vt[here].size() ; i++){
		int there=vt[here][i];
		erase(there);	
	}
}

void dfs(int here ){
	visited[here] = true;
	int vvvv=vt[here].size();
	for(int i = 0 ; i < vt[here].size() ; i++){
		int there = vt[here][i];
		if(isErased[there]) {
			vvvv--;
		}
		else if(visited[there] == false ) dfs(there);
	}
	if(vvvv == 0) {
		cnt++;
	}
}



int main(){
	freopen("input.txt" , "r" , stdin);
	scanf("%d" , &N);
	vt.resize(N+1);
	for(int i = 0 ; i < N ; i++){
		scanf("%d" , &x);
		if(x == -1) root = i;
		else {
			vt[x].push_back(i);	
		}
	}
	scanf("%d" , &y);
	erase(y);

	memset(visited,0,sizeof(visited));

	for(int i = 0 ; i < N ; i++){
		if(visited[i] == false && !isErased[i]) dfs(i);
	}

	printf("%d\n", cnt);
}

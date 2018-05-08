#include <cstdio>
#include <cstring>
#include <vector>


using namespace std;

int point , N;
int X1,X2;
vector <vector <int> > input;
bool visited[1004][1004];
int cnt;

void dfs(int x , int y){
	visited[x][y] = true;
	for(int i = 0 ; i < input[x].size() ; i++){
		if(visited[x][i] == true) continue;
		dfs(x,i); 
	}
}


int main(){
	freopen("input.txt" , "r" , stdin);
	scanf("%d %d" , &point , &N);
	while(N--){
		scanf("%d %d" , &X1 , &X2);
		input[X1].push_back(X2);
	}

	for(int i = 1 ; i <= point ; i++){
		for(int j = 0 ; j < input[i].size() ; j++){
			if(visited[i][j] == false){
				dfs(i,j);
				cnt++;
			}
		}
	}
}

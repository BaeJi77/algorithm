#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int T;
vector <vector <int> > input;
bool visited[104];
int IN;

void dfs(int here){
	visited[here]=true;
	for(int i=0;i<input[here].size();i++){
		int there = input[here][i];
		if(visited[there]) continue;
		dfs(there);
	}
}

int main(){
	freopen("input.txt" , "r" , stdin);
	scanf("%d" , &T);
	input.resize(T+1);
	for(int i = 1 ; i <= T ; i++){
		for(int j = 1 ; j <= T ; j++){
			scanf("%d" , &IN);
			if(IN == 1){
				input[i].push_back(j);
			}
		}
	}
	for(int i = 1 ; i <= T ; i++){
		memset(visited , 0 , sizeof(visited));
		for(int j=0;j<input[i].size();j++){
			int there=input[i][j];
			// printf("%d\n", there);
			dfs(there);
		}
		for(int j = 1 ; j <= T ; j++){
			if(visited[j]) printf("1 ");
			else printf("0 ");
		}
		puts("");
	}

}

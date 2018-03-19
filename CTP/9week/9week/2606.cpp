<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 69999cd... 18.05.29
//#include <cstdio>
//#include <cstring>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//int n,m,v,x,y;
//vector <vector <int> > vt;
//bool visited[10004];
//int cnt;
//
//void dfs(int here){
//    visited[here] = true;
//    if(here != 1) cnt++;
//    for(int i = 0 ; i < vt[here].size() ; i++){
//        int there = vt[here][i];
//        if(visited[there] == false) dfs(there);
//    }
//}
//
//int main(){
//    scanf("%d" , &n);
//    scanf("%d" , &m);
//    vt.resize(n+1);
//    while(m--){
//        scanf("%d%d" , &x, &y);
//        vt[x].push_back(y);
//        vt[y].push_back(x);
//    }
//    
//    dfs(1);
//    printf("%d" , cnt);
//}
//
<<<<<<< HEAD
=======
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n,m,v,x,y;
vector <vector <int> > vt;
bool visited[10004];

queue <int> qu;
bool discover[10004];



int main(){
	freopen("input.txt" , "r" , stdin);
	scanf("%d" , &n);
	scanf("%d" , %m);
	while(m--){
		scanf("%d%d" , &x, &y);
		vt[x].push_back(y);
	}

	for(int i = 0 ; i < n ; i++){
		
	}
	
}
>>>>>>> 7b46f3b... 18.05.24
=======
>>>>>>> 69999cd... 18.05.29

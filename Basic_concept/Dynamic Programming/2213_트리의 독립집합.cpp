#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<vector<int> > map;
vector<vector<int> > tree;
int cost[10001];
int path[10001];
bool visited[10001];

void makeTree(int here){
    visited[here] = true;
    for(int i = 0 ; i < map[here].size(); i++){
        int next = map[here][i];
        if(visited[next])
            continue;
        tree[here].push_back(next);
        makeTree(next);
    }
}

int func(int here, int select){
    int ans = 0;
    int maxIdx = 0;
    int maxVal = -1;
    for(int i = 0; i  < tree[here].size(); i++){
        int next = tree[here][i];
        int nowCost = 0;
        if(select == 1){
            nowCost += func(next, 0);
        }else{
            nowCost += max(func(next, 0), func(next, 1) + cost[next]);
        }
        if(maxVal < nowCost){
            maxIdx = i;
            maxVal = nowCost;
        }
        ans += nowCost;
    }

    if(select == 1){
        path[here] = 1;
        
    }

    return ans;
}




int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++)
        scanf("%d", &cost[i]);
    
    for(int i = 0 ; i < N ; i++){
        int a,b;
        scanf("%d %d", &a,&b);
        map[a].push_back(b);
        map[b].push_back(a);
    }

    makeTree(1);
    // memset(cache,-1,sizeof(cache));
}
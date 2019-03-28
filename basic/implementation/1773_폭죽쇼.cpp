#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 2e6;

int N,C;
bool visited[MAX+1];
bool check[MAX+1];

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d", &N, &C);
    priority_queue<pair<int, int> > pq;
    for(int i = 0 ; i < N ; i++){
        int a;
        scanf("%d", &a);
        if(check[a] == false)
            pq.push(make_pair(-a,a));
        check[a] = true;
    }

    for(int i = 1 ; i <= C ; i++){
        while(i == -pq.top().first){
            int top = -pq.top().first;
            int nextPos = top + pq.top().second;
            pq.push(make_pair(-nextPos, pq.top().second));
            pq.pop();
            visited[top] = true;
        }
    }

    int cnt = 0;
    for(int i = 1 ; i <= C ; i++){
        if(visited[i] == true)
            cnt++;
    }

    printf("%d", cnt);
}
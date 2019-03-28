#include <cstdio>
#include <queue>

using namespace std;

int N;
queue<int> qu;

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++)
        qu.push(i); 
    while(qu.size() != 1){
        qu.pop();
        int front = qu.front();
        qu.pop();
        qu.push(front);
    }

    printf("%d", qu.front());
}
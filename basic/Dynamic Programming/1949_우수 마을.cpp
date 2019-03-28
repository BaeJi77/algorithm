#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 10000;

int N, people[MAX+1];
vector<vector<int> > vt;

int func(){

}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d", &N);
    for(int i = 0 ; i < N ; i++){
        scanf("%d", &people[i]);
    }
    vt.resize(N+1);
    for(int i = 0 ; i < N-1 ; i++){
        int a, b;
        scanf("%d %d", &a,&b);
        vt[a].push_back(b);
        vt[b].push_back(a);
    }



}
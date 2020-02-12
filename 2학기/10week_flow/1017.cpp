#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int N,B[54],input[54],p[10004],first;
bool visited[54];

vector<vector<int> > vt;
vector<int> ret;

bool dfs(int here){
    // visited[here] = true;
    for(int i = 0 ; i < vt[here].size() ; i++){
        int there = vt[here][i];
        if(here == there || p[here+there] == true)
            continue;
        if(B[there] == -1 || !visited[B[there]] && dfs(B[there])){
            visited[here] = true;
            B[there] = here;
            return true;
        }
    }
    return false;
}

void findP(){
    p[0] = true;
    p[1] = true;
    for(int i = 2 ; i <= sqrt(1000) ; i++){
        if(p[i] == true)
            continue;
        for(int j = i*2 ; j <= 1000 ; j+=i){
            p[j] = true;
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    findP();
    scanf("%d" , &N);
    vt.resize(N+1);
    for(int i = 0 ; i < N ; i++){
        int a;
        scanf("%d" , &input[i]);
        if(i==0) 
            first = input[i];
    }

    for(int i = 0 ; i < N ; i++){
        if(i==0)
            continue;
        for(int j = 0 ; j < N ; j++){
            vt[input[i]].push_back(input[j]);
        }
    }

    
    for(int i = 1 ; i < N ; i++){
        int kk = first + input[i];
        if(p[kk] == true)
            continue;
        memset(B,-1,sizeof(B));
        memset(visited,0,sizeof(visited));
        bool good = true;
        for(int j = 1; j < N ; j++){
            if(!dfs(input[j]))
                good = false;
        }
        if(good == true)
            ret.push_back(input[i]);
    }

    for(int i = 0 ; i < ret.size();i++){
        printf("%d " , ret[i]);
    }
}
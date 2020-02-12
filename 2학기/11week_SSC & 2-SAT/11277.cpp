#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>

#define MAX 100
using namespace std;

int n,m,samescc[2*MAX+4];
bool visited[2*MAX+4];

stack<int> st;
vector<vector<int> > vt;
vector<vector<int> > rvt;
vector<vector<int> > scc;


void dfs(int here){
    visited[here] = true;
    for(auto there : vt[here])
        if(visited[there] == false)
            dfs(there);
    st.push(here);
}

void mscc(int here,int cnt){
    visited[here] = true;
    scc[cnt].push_back(here);
    samescc[here] = cnt;
    for(auto there : rvt[here])
        if(visited[there] == false)
            mscc(there,cnt);
}

int f(int k){
    return k>n ? k-n : k+n;
}


int main(){
    freopen("input.txt","r",stdin);
    scanf("%d %d" , &n,&m);
    vt.resize(2*n+1);
    rvt.resize(2*n+1);
    scc.resize(2*n+1);
    // printf("%d %d\n" , n,m);
    for(int i = 0 ; i < m ; i++){
        int a,b;
        scanf("%d %d", &a,&b);
        if(a<0) a = a*(-1)+n;
        if(b<0) b = b*(-1)+n;
        vt[f(a)].push_back(b);
        rvt[b].push_back(f(a));
        vt[f(b)].push_back(a);
        rvt[a].push_back(f(b));
    }

    for(int i = 1 ; i <= 2*n ; i++){
        if(visited[i] == false)
            dfs(i);
    }

    int cnt=0;
    memset(visited , 0, sizeof(visited));
    for(int i = 0 ; i < 2*n ; i++){
        int top = st.top();
        st.pop();
        if(visited[top] == true) continue;
        scc.resize(++cnt);
        mscc(top,cnt-1);
    }

    bool flag = true;
    for(int i = 1 ; i <= n ; i++ ){
        if(samescc[i] == samescc[i+n]){
            flag = false;
        }
    }

    if(flag) printf("1\n");
    else printf("0\n");
}
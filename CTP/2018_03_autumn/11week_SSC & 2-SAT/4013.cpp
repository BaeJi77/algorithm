#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>


#define MAX 500000
using namespace std;

int n,m,sccValue[MAX+4],atmValue[MAX+4];
bool visited[MAX+4];
stack<int> st;
vector<vector<int> > vt;
vector<vector<int> > rvt;
vector<vector<int> > scc;

void dfs(int here){
    visited[here] = true;
    for(auto there : vt[here]){
        if(visited[there] == false){
            dfs(there);
        }
    }
    st.push(here);
}

int make(int here,int cnt){
    int ret = atmValue[here];
    visited[here] = true;
    scc[cnt].push_back(here);
    for(auto there : rvt[here]){
        if(visited[there] == false)
            ret += make(there,cnt);
    }
    return ret;
}

int main(){
    scanf("%d %d" , &n,&m);
    vt.resize(n+1);
    rvt.resize(n+1);
    for(int i = 0 ; i < m ; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        vt[a].push_back(b);
        rvt[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i++){
        int val;
        scanf("%d" ,&val);
        atmValue[i]= val;
    }

    for(int i = 0 ; i < n ; i++){
        if(visited[i]==false){
            dfs(i);
        }
    }

    int cnt=0;
    memset(visited, 0 , sizeof(visited));
    for(int i = 0 ; i < n ; i++){
        int top = st.top();
        st.pop();
        if(visited[top] == true) continue;
        scc.resize(++cnt);
        sccValue[cnt] = make(top,cnt-1);
    }

    




}
